
// PlathosysApi.h

#ifdef PLATHOSYSAPIDLL_EXPORTS
#define PLATHOSYSAPIDLL_API __declspec(dllexport) 
#else
#define PLATHOSYSAPIDLL_API __declspec(dllimport) 
#endif




namespace PlathosysApiFuncs
{
	class	PlathosysFn
	{
	public:
		static PLATHOSYSAPIDLL_API unsigned int PlathosysFn::ApiVersionNumber();		//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::Opendevice(unsigned int VendorID,unsigned int ProductID,unsigned int *GotVendorID,unsigned int *GotProductID, char *GotProductName, char *SerialNumber);
		static PLATHOSYSAPIDLL_API int PlathosysFn::Closedevice();
		static PLATHOSYSAPIDLL_API int PlathosysFn::IsDeviceOpen();
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetHandsetVolume(unsigned int Volume);			//Do not use in new software client. (Use SetHandsetVolume() )
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetHeadsetVolume(unsigned int Volume);			//Do not use in new software client. (Use SetHeadsetdBVolume() )
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetIntSpeakerVolume(unsigned int Volume);		//Do not use in new software client. (Use SetIntSpeakerdBVolume() )
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetIntSpeakerMute(bool State);
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetHandsetMicVolume(unsigned int Volume);		//Do not use in new software client. (Use SetHandsetdBMicVolume() )
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetHeadsetMicVolume(unsigned int Volume);		//Do not use in new software client. (Use SetHeadsetdBMicVolume() )
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetExtMicVolume(unsigned int Volume);			//Do not use in new software client. (Use SetExtMicdBVolume() )
		static PLATHOSYSAPIDLL_API int PlathosysFn::ReadCurrentInfo(unsigned char *Info1,unsigned char *Info2,unsigned char *Info3,unsigned char *Info4,unsigned char *Info5,unsigned char *Info6,
																	unsigned char *Info7,unsigned char *Info8,unsigned char *Info9,unsigned char *Info10); //Do not use in new software client. (Use ReadCurrentInfodB() )
		static PLATHOSYSAPIDLL_API int PlathosysFn::ReadHookAndPTT(unsigned int *HookPttInfo);
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetSideTone(int OnOff);
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetMicMute(int OnOff);
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetSpeakerOutMute(int OnOff);
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetWideBand(int OnOff);							//Only with PID 0x0001,0x0002 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetEchoCanseller(int OnOff);					//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetExtMic(bool State);							//Only with PID 0x0001,0x0002 devices 
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetConference(bool State);						//Only with PID 0x0001,0x0002 devices 	
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetHeadsetActive(bool State);					//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetWirelessHeadsetRinging(bool State);			//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetWirelessCall(bool State);					//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetPttFunctions(unsigned int InVal);			//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetHeadsetEar(int OnOffRelease);				//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetExtmicLed(bool State);						//Only with PID 0x0001,0x0002 devices 	
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetByListening(bool State);
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetCodecType(int CodecType);					//Only with PID 0x0001,0x0002 devices 	
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetSerialNumber(unsigned long Serno);			//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::InitHookAndPTTState();
		static PLATHOSYSAPIDLL_API int PlathosysFn::MuteSpkCt140(bool State);						//Only PID 0x0003,0x0004 devices	
		static PLATHOSYSAPIDLL_API int PlathosysFn::MuteMicCt140(bool State);						//Only PID 0x0003,0x0004 devices	
	
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetHeadsetdBVolume(int dBVolume);						//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetHeadsetMicdBVolume(int dBVolume);					//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetExtMicdBVolume(int dBVolume);						//Only with PID 0x0001,0x0002 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetIntSpeakerdBVolume(int dBVolume);					//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetIntAlarmSpeakerdBVolume(int dBVolume);				//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetIntAlarmSpeakerVolume(unsigned int Volume);			//Not with PID 0x0003,0x0004 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::SetLyncFeature(unsigned int Feature );					//Only with PID 0x0005,0x0006 devices
		static PLATHOSYSAPIDLL_API int PlathosysFn::ReadCurrentInfodB(unsigned char *Info1,unsigned char *Info2,unsigned char *Info3,unsigned char *Info4,unsigned char *Info5,unsigned char *Info6,
																	unsigned char *Info7,unsigned char *Info8,unsigned char *Info9,unsigned char *Info10,
																	char *Info11,char *Info12,char *Info13, char *Info14, char *Info15,unsigned char *Info16);  //Not with PID 0x0003,0x0004 devices
	};
}




