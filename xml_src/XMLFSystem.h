//---------------------------------------------------------------------------

#ifndef XMLFSystemH
#define XMLFSystemH
//---------------------------------------------------------------------------
#endif

class XMLFSystem {
	public:
		bool xmlCreateDir(const char *szDirPath, LPSECURITY_ATTRIBUTES lpSA);

		void __fastcall DelDir(AnsiString Dir);
		private:



};
