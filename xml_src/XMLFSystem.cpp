// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "XMLFSystem.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

bool XMLFSystem::xmlCreateDir(const char *szDirPath, LPSECURITY_ATTRIBUTES lpSA)
{

	const char szSlash[] = "\\";
	BOOL bRet = TRUE;

	if (!strstr(szDirPath, szSlash)) {
		return CreateDirectoryA(szDirPath, lpSA);
	}
	char* szDblDirPath = new char[strlen(szDirPath) + 1];
	strcpy(szDblDirPath, szDirPath);
	char* pszDblDirPath = szDblDirPath;

	while (pszDblDirPath != NULL && bRet == TRUE) {
		pszDblDirPath = strstr(pszDblDirPath, szSlash);
		if (pszDblDirPath != NULL) {
			if (*(pszDblDirPath - 1) == ':' && strstr(pszDblDirPath + 1,
				szSlash) == 0) {
				bRet = CreateDirectoryA(pszDblDirPath, lpSA);
				break;
			}
			if (*(pszDblDirPath - 1) == ':') {
				pszDblDirPath = strstr(pszDblDirPath + 1, szSlash);
			}
			*pszDblDirPath = 0;
			if (!::CreateDirectoryA(szDblDirPath, lpSA)) {
				if (::GetLastError() != ERROR_ALREADY_EXISTS) {
					bRet = FALSE;
					break;
				}
			}
			if (pszDblDirPath) {
				*pszDblDirPath = szSlash[0];
				++pszDblDirPath;
			}
		}
	}
	delete szDblDirPath;
	return bRet;

}

void __fastcall XMLFSystem::DelDir(AnsiString DirName) {
	TSearchRec sr;
	if (DirName.Length()) {
		if (!FindFirst(DirName + "\\*.*", faAnyFile, sr))
			do {
				if (!(sr.Name == "." || sr.Name == "..")) // это не удаляем
					if (((sr.Attr & faDirectory) == faDirectory) ||
						(sr.Attr == faDirectory)) // найдена папка
					{
						FileSetAttr(DirName + "\\" + sr.Name, faDirectory);
						DelDir(DirName + "\\" + sr.Name);
						// рекурсивно удаляем найденную папку
						RemoveDir(DirName + "\\" + sr.Name);
						// удаляем уже пустую папку
					}
					else // найден файл
					{
						FileSetAttr(DirName + "\\" + sr.Name, 0);
						DeleteFile(DirName + "\\" + sr.Name); // удаляем файл
					}
			}
			while (!FindNext(sr)); // ищем пока не найдем все
		FindClose(sr);
	}
	RemoveDir(DirName);
	this->xmlCreateDir(AnsiString(DirName).c_str(), NULL);
	return;
}
