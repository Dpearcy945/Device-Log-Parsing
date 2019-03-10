#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <fstream>

using namespace std;
using namespace boost;

int main(int argc, char* argv[]){
	//int lineScanned = 0;
	int sInit = 0, sComp = 0, scannedLines = 0;
	bool isComp = true;
	string eStr = "File Failed to Load!";
	string oFilename = argv[1];
	oFilename.append(".rpt");	
	ifstream logfile(argv[1]);
	ofstream rptfile(oFilename.c_str());
	//logfile.open(argv[1]);
	try{

		if(!logfile.is_open()){
			throw eStr;
		}
		if(!rptfile.is_open()){
			throw eStr;
		}
	}
	catch(const char* eStr){
		cerr << eStr << endl;
	}
	const string start = "(.log.c.166)(.+)",end = "(oejs.AbstractConnector:Started)(.+)";
	string str,tStr, logdate = "^([0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}:)" ;
	string logdate2 = "([0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}.[0-9]{3}:)";
	regex serverStart, serverStop,dateCheck, dateCheck2;
	
	try{
		//e = regex(rStr1);
		dateCheck = logdate;
		dateCheck2 = logdate2;
		serverStop = end;
		serverStart = start;
	}
	catch(regex_error& exc){
		cout << "Regex constructor failed with code" << exc.code() << endl;
		exit(1);
	}
	rptfile << "Device Report: " << argv[1] <<endl << endl << endl;
	while(getline(logfile, str)){
		++scannedLines;
		smatch endM, startM, dateM1, dateM2;

		if(regex_search(str, dateM1, dateCheck)||regex_search(str, dateM2, dateCheck2)){
			if(regex_search(str, startM, serverStart)){
				if(!isComp)
					rptfile << "Device Boot has failed to complete"<< endl;
				rptfile << endl; 
				sInit += 1;
				rptfile << scannedLines << "(" << argv[1] << "):" << dateM1[1] << "Boot Start" << endl;
				isComp = false;
			}
			if(regex_search(str, endM, serverStop)){
				sComp += 1;
				rptfile << scannedLines << "(" << argv[1] << "):" << dateM2[1] << "Boot Completed" << endl;
				isComp = true;
			}
		}
	}
	rptfile << endl << "Boot Starts: " <<sInit <<" :: " << "Boot completions: " <<sComp <<"		Scanned Lines: " << scannedLines << endl;
	rptfile.close();
	logfile.close();
	return 0;
}
