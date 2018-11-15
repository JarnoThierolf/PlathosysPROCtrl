// Plathosys-PRO-Ctrl
// Version: 1.0.0.1
// Author: Jarno Thierolf, Horst Platz GmbH
// Command line program to control the external accessories at the PRO series.
//

#include "stdafx.h"
#include <iostream>
#include <PlathosysApi.h>

// for TRUE and FALSE and for Sleep function
#include <windows.h>

using namespace std;

// hide console window for normal use (this will hide console output as well)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")


int main(int argc, char* argv[])
{
	int ret;   //return value

	// ouput program name and version
	cout << endl;
	cout << "######################" << endl;
	cout << "# Plathosys-PRO-Ctrl #" << endl;
	cout << "# Version: 1.0.0.1   #" << endl;
	cout << "######################" << endl << endl;


	// output help message when no parameter is passed
	if (argc < 2)
	{
		cerr << "Usage: " << "Plathosys-PRO-Ctrl.exe parameter1 parameter2 parameter3 ..." << endl;
		cout << endl;
		cout << "Please pass one or more of the following parameter to the application:" << endl;
		cout << "-h or --help -> will show this help message" << endl;
		cout << "headsetOn -> activates the headset port" << endl;
		cout << "headsetOff -> deactivates the headset port" << endl;
		cout << "speakerOn -> activates the internal or external speaker" << endl;
		cout << "speakerOff -> deactivates the internal or external speaker" << endl;
		cout << "headsetEarOn -> activates only the receiving stream of the headset port" << endl;
		cout << "headsetEarOff -> deactivates only the receiving stream of the headset port" << endl;
		cout << endl;
		return 0;
	}


	// open the device

	unsigned int SelectedVendorID;
	unsigned int SelectedProductID;
	char DeviceName[200];
	char SerialNumber[200];

	ret = PlathosysApiFuncs::PlathosysFn::Opendevice(0x0000, 0x0000, &SelectedVendorID, &SelectedProductID, DeviceName, SerialNumber);		//Select first from list of plathosys devices
	if (ret == TRUE)
	{
		cout << "Device opened" << endl;
		cout << endl;
	}
	if (ret == FALSE)
	{
		cout << "Device not connected" << endl;
		cout << endl;
		return 0;
	}
	if (ret == -1)
	{
		cout << "Device allready open" << endl;
		cout << endl;
	}


	/*
	//reed current infos

	unsigned int k;
	unsigned char ReadInfo1;
	unsigned char ReadInfo2;
	unsigned char ReadInfo3;
	unsigned char ReadInfo4;
	unsigned char ReadInfo5;
	unsigned char ReadInfo6;
	unsigned char ReadInfo7;
	unsigned char ReadInfo8;
	unsigned char ReadInfo9;
	unsigned char ReadInfo10;
	char ReadInfo11;
	char ReadInfo12;
	char ReadInfo13;
	char ReadInfo14;
	char ReadInfo15;
	unsigned char ReadInfo16;

	char s[200];

	ret = PlathosysApiFuncs::PlathosysFn::ReadCurrentInfodB(&ReadInfo1,&ReadInfo2,&ReadInfo3,&ReadInfo4,&ReadInfo5,&ReadInfo6,&ReadInfo7,&ReadInfo8,&ReadInfo9,&ReadInfo10,
			&ReadInfo11,&ReadInfo12,&ReadInfo13,&ReadInfo14,&ReadInfo15,&ReadInfo16);

	cout << "ret: " << ret << endl;

	if (ReadInfo6 & 0x0040)
		cout << "bylistening = 1" << endl;
	else
		cout << "bylistening = 0" << endl;

	if (ReadInfo5 & 0x0002)
		cout << "HeadsetEar = 1" << endl;
	else
		cout << "HeadsetEar = 0" << endl;
	if (ReadInfo1 & 0x0002)
		cout << "Headset = 1" << endl;
	else
		cout << "Headset = 0" << endl;
	if (ReadInfo1 & 0x0002)
	*/


	// loop through passed arguments
	for (int i = 1; i < argc; i++)
	{
		// detection of parameter
		if (string(argv[i]) == "headsetOn")
		{
			ret = PlathosysApiFuncs::PlathosysFn::SetHeadsetEar(2);  // 2 -> off
			if (ret == FALSE)
				cout << "Command \"headsetEarOff\" failed (started because of \headsetON\")" << endl;
			else
			{
				ret = PlathosysApiFuncs::PlathosysFn::SetHeadsetActive(TRUE);
				if (ret == FALSE)
					cout << "Command \"headsetOn\" failed" << endl;
				else
					cout << "Headset port activated" << endl;
			}
		}
		else if (string(argv[i]) == "headsetOff")
		{
			ret = PlathosysApiFuncs::PlathosysFn::SetHeadsetActive(FALSE);
			if (ret == FALSE)
				cout << "Command \"headsetOFF\" failed" << endl;
			else
				cout << "Headset port deactivated" << endl;	
		}
		else if (string(argv[i]) == "speakerOn")
		{
			ret = PlathosysApiFuncs::PlathosysFn::SetByListening(TRUE);
			if (ret == FALSE)
				cout << "Command \"speakerOn\" failed" << endl;
			else
				cout << "Speaker port is activated" << endl;
		}
		else if (string(argv[i]) == "speakerOff")
		{
			ret = PlathosysApiFuncs::PlathosysFn::SetByListening(FALSE);
			if (ret == FALSE)
				cout << "Command \"speakerOff\" failed" << endl;
			else
				cout << "Speaker port is deactivated" << endl;
		}
		else if (string(argv[i]) == "headsetEarOn")
		{
			ret = PlathosysApiFuncs::PlathosysFn::SetHeadsetActive(FALSE);   // deactivate headset, so that sending stream is deactivated
			if (ret == FALSE)
				cout << "Command \"headsetOff\" failed (started because of \headsetEarON\")" << endl;
			else
			{
				ret = PlathosysApiFuncs::PlathosysFn::SetHeadsetEar(1);
				if (ret == FALSE)
					cout << "Command \"headsetEarOn\" failed" << endl;
				else
					cout << "Second handset / headset is activated" << endl;
			}
		}
		else if (string(argv[i]) == "headsetEarOff")
		{
			ret = PlathosysApiFuncs::PlathosysFn::SetHeadsetActive(FALSE);   // deactivate headset, so that sending stream is deactivated
			if (ret == FALSE)
				cout << "Command \"headsetOff\" failed (started because of \headsetEarON\")" << endl;
			else
			{
				ret = PlathosysApiFuncs::PlathosysFn::SetHeadsetEar(2);
				if (ret == FALSE)
					cout << "Command \"headsetEarOff\" failed" << endl;
				else
					cout << "Second handset / headset is deactivated" << endl;
			}
		}
		else if (string(argv[i]) == "-h" || string(argv[i]) == "--help")
		{
			cerr << "Usage: " << "Plathosys-PRO-Ctrl.exe parameter1 parameter2 parameter3 ..." << endl;
			cout << endl;
			cout << "Please pass one or more of the following parameter to the application:" << endl;
			cout << "-h or --help -> will show this help message" << endl;
			cout << "headsetOn -> activates the headset port" << endl;
			cout << "headsetOff -> deactivates the headset port" << endl;
			cout << "speakerOn -> activates the internal or external speaker" << endl;
			cout << "speakerOff -> deactivates the internal or external speaker" << endl;
			cout << "headsetEarOn -> activates only the receiving stream of the headset port" << endl;
			cout << "headsetEarOff -> deactivates only the receiving stream of the headset port" << endl;
			cout << endl;
		}
		else    // parameter unknown
		{
			cout << "The parameter \"" << argv[i] << "\" is not known, please check the help with parameter --help or -h." << endl;
			cout << endl;
		}
	}


	//close device
	ret = PlathosysApiFuncs::PlathosysFn::Closedevice();
	cout << endl;
	if (ret == TRUE)
		cout << "Device closed" << endl;
	if (ret == FALSE)
		cout << "Command \"Closedevice\" failed" << endl;
	cout << endl;


	// keep console window open
	// cout << endl << "Press Enter to close the program" << endl;
	// cin.get();


    return 0;
}

