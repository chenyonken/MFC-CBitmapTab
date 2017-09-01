# Microsoft Developer Studio Generated NMAKE File, Based on BmpTab.dsp
!IF "$(CFG)" == ""
CFG=BmpTab - Win32 Debug
!MESSAGE No configuration specified. Defaulting to BmpTab - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "BmpTab - Win32 Release" && "$(CFG)" != "BmpTab - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BmpTab.mak" CFG="BmpTab - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BmpTab - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "BmpTab - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BmpTab - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\BmpTab.exe"


CLEAN :
	-@erase "$(INTDIR)\BitmapTab.obj"
	-@erase "$(INTDIR)\BmpTab.obj"
	-@erase "$(INTDIR)\BmpTab.pch"
	-@erase "$(INTDIR)\BmpTab.res"
	-@erase "$(INTDIR)\BmpTabDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\BmpTab.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\BmpTab.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\BmpTab.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\BmpTab.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\BmpTab.pdb" /machine:I386 /out:"$(OUTDIR)\BmpTab.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BmpTab.obj" \
	"$(INTDIR)\BmpTabDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\BmpTab.res" \
	"$(INTDIR)\BitmapTab.obj"

"$(OUTDIR)\BmpTab.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "BmpTab - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\BmpTab.exe" "$(OUTDIR)\BmpTab.bsc"


CLEAN :
	-@erase "$(INTDIR)\BitmapTab.obj"
	-@erase "$(INTDIR)\BitmapTab.sbr"
	-@erase "$(INTDIR)\BmpTab.obj"
	-@erase "$(INTDIR)\BmpTab.pch"
	-@erase "$(INTDIR)\BmpTab.res"
	-@erase "$(INTDIR)\BmpTab.sbr"
	-@erase "$(INTDIR)\BmpTabDlg.obj"
	-@erase "$(INTDIR)\BmpTabDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\BmpTab.bsc"
	-@erase "$(OUTDIR)\BmpTab.exe"
	-@erase "$(OUTDIR)\BmpTab.ilk"
	-@erase "$(OUTDIR)\BmpTab.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\BmpTab.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\BmpTab.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\BmpTab.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\BmpTab.sbr" \
	"$(INTDIR)\BmpTabDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\BitmapTab.sbr"

"$(OUTDIR)\BmpTab.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\BmpTab.pdb" /debug /machine:I386 /out:"$(OUTDIR)\BmpTab.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BmpTab.obj" \
	"$(INTDIR)\BmpTabDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\BmpTab.res" \
	"$(INTDIR)\BitmapTab.obj"

"$(OUTDIR)\BmpTab.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("BmpTab.dep")
!INCLUDE "BmpTab.dep"
!ELSE 
!MESSAGE Warning: cannot find "BmpTab.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "BmpTab - Win32 Release" || "$(CFG)" == "BmpTab - Win32 Debug"
SOURCE=.\BitmapTab.cpp

!IF  "$(CFG)" == "BmpTab - Win32 Release"


"$(INTDIR)\BitmapTab.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\BmpTab.pch"


!ELSEIF  "$(CFG)" == "BmpTab - Win32 Debug"


"$(INTDIR)\BitmapTab.obj"	"$(INTDIR)\BitmapTab.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\BmpTab.pch"


!ENDIF 

SOURCE=.\BmpTab.cpp

!IF  "$(CFG)" == "BmpTab - Win32 Release"


"$(INTDIR)\BmpTab.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\BmpTab.pch"


!ELSEIF  "$(CFG)" == "BmpTab - Win32 Debug"


"$(INTDIR)\BmpTab.obj"	"$(INTDIR)\BmpTab.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\BmpTab.pch"


!ENDIF 

SOURCE=.\BmpTab.rc

"$(INTDIR)\BmpTab.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\BmpTabDlg.cpp

!IF  "$(CFG)" == "BmpTab - Win32 Release"


"$(INTDIR)\BmpTabDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\BmpTab.pch"


!ELSEIF  "$(CFG)" == "BmpTab - Win32 Debug"


"$(INTDIR)\BmpTabDlg.obj"	"$(INTDIR)\BmpTabDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\BmpTab.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "BmpTab - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\BmpTab.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\BmpTab.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "BmpTab - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\BmpTab.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\BmpTab.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

