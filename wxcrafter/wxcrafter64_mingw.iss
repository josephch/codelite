; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=wxCrafter
AppVerName=wxCrafter
AppPublisher=Eran Ifrah
AppVersion=3.0
AppPublisherURL=http://wxcrafter.org
AppSupportURL=http://wxcrafter.org
AppUpdatesURL=http://wxcrafter.org
DefaultDirName={pf64}\wxCrafter
DefaultGroupName=wxCrafter
LicenseFile=..\LICENSE
OutputDir=..\InnoSetup\output\
OutputBaseFilename=wxcrafter-amd64-3.0
ChangesEnvironment=yes
FlatComponentsList=yes
SetupIconFile=box_software.ico
Compression=lzma/ultra
SolidCompression=true
InternalCompressLevel=ultra
PrivilegesRequired=none
UninstallDisplayIcon={app}\wxcrafter.exe,0

;;==================================
;; 64 bit setup
;;==================================
#define CODELITE_ROOT "C:\src\codelite"
#define WXWIN "C:\msys64\home\eran\root"
#define MSYS2_DIR "C:\msys64\usr\bin"
#define MINGW_DIR "C:\msys64\clang64\bin"
#define BUILD_BIN_DIR "C:\src\codelite\wxcrafter\build-Release_Standalone\bin"
#define WX_CONFIG_DIR "C:\msys64\home\eran\devl\wx-config-msys2\bin"
#define MINGW_INSTALL_DIR "C:\msys64\home\eran\root"

[Languages]
Name: "eng"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "{#BUILD_BIN_DIR}\wxcrafter.exe"; DestDir: "{app}"; Flags: ignoreversion;

;; ---- wxWidgets DLLs
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxbase316u_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxbase316u_net_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxbase316u_xml_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_adv_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_aui_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_core_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_html_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_propgrid_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_richtext_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_stc_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_xrc_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
;;Source: "{#WXWIN}\lib\gcc_x64_dll\wxmsw316u_ribbon_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion;
Source: "{#WXWIN}\lib\clang_x64_dll\wxmsw32u_clang.dll"; DestDir: "{app}"; Flags: ignoreversion;

;; ---- MinGW64 Dlls
Source: "{#MINGW_DIR}\libc++.dll"; DestDir: "{app}"; Flags: ignoreversion;
Source: "{#MINGW_DIR}\libunwind.dll"; DestDir: "{app}"; Flags: ignoreversion;
Source: "{#MINGW_DIR}\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion;

;; ---- Binaries
Source: "{#CODELITE_ROOT}\InnoSetup\license.txt"; DestDir: "{app}"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\config\codelite.xml.default"; DestDir: "{app}\config";

;; ------- Bin Utils ------------------
Source: "{#MSYS2_DIR}\msys-intl-8.dll"; DestDir: "{app}"; Flags: ignoreversion;
Source: "{#MSYS2_DIR}\msys-2.0.dll"; DestDir: "{app}"; Flags: ignoreversion;
Source: "{#MSYS2_DIR}\msys-iconv-2.dll"; DestDir: "{app}"; Flags: ignoreversion;

; Override with Windows specific files
Source: "{#CODELITE_ROOT}\LICENSE"; DestDir: "{app}"; Flags: ignoreversion;

; XML settings
Source: "{#CODELITE_ROOT}\Runtime\lexers\*.json"; DestDir: "{app}\lexers\"; Flags: ignoreversion ;

; Copy core DLLs
Source: "{#CODELITE_ROOT}\Runtime\libwxsqlite3u.dll"; DestDir: "{app}"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\libcodeliteu.dll"; DestDir: "{app}"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\libplugin_sdku.dll"; DestDir: "{app}"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\libdatabaselayersqliteu.dll"; DestDir: "{app}"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\libwxshapeframeworku.dll"; DestDir: "{app}"; Flags: ignoreversion ;
Source: "{#MINGW_INSTALL_DIR}\bin\libssh.dll"; DestDir: "{app}\"; DestName: "libssh.dll"; Flags: ignoreversion ;
Source: "{#MINGW_DIR}\zlib1.dll"; DestDir: "{app}\"; DestName: "zlib1.dll"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\images\*"; DestDir: "{app}\images"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\images\*"; DestDir: "{app}\images"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\*.zip"; DestDir: "{app}"; Flags: ignoreversion ;
Source: "{#CODELITE_ROOT}\Runtime\locale\*"; DestDir: "{app}\locale"; Flags: recursesubdirs ;
Source: "{#CODELITE_ROOT}\Runtime\wxgui.zip";  DestDir: "{app}"; Flags: ignoreversion;

[Icons]
Name: "{group}\wxCrafter "; Filename: "{app}\wxcrafter.exe"; WorkingDir: "{app}"
Name: "{group}\{cm:UninstallProgram, wxCrafter}"; Filename: "{uninstallexe}"
Name: "{userdesktop}\wxCrafter "; Filename: "{app}\wxcrafter.exe"; WorkingDir: "{app}" ;Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\wxCrafter"; WorkingDir: "{app}"; Filename: "{app}\wxcrafter.exe"; Tasks: quicklaunchicon

[INI]

[Registry]
Root: HKLM; Subkey: "Software\wxcrafter\settings"; ValueType: string; ValueName: "InstallPath"; ValueData: "{app}"; Flags: noerror

[UninstallDelete]
Type: filesandordirs; Name: "{app}"

[Run]
Filename: "{app}\wxcrafter.exe"; Description: "Launch wxCrafter"; Flags: postinstall nowait skipifsilent

[Code]
var
    // Globals
    sMinGWFolderName: String;
    bMinGWBackedUp: Boolean;

// Uninstall
procedure CurUninstallStepChanged(CurUninstallStep: TUninstallStep);
begin
  case CurUninstallStep of
    usUninstall:
      begin
        RegDeleteKeyIncludingSubkeys(HKCR, '*\shell\Open With wxCrafter');
        // Prompt the user to delete all his settings, default to "No"
        if MsgBox('Would you like to keep your user settings?', mbConfirmation, MB_YESNO or MB_DEFBUTTON1) = IDNO
        then begin
            DelTree(ExpandConstant('{userappdata}') + '\wxcrafter', True, True, True);
        end;
      end;
    usPostUninstall:
      begin
      end;
  end;
end;

//--------------------
// Uninstall
//--------------------

function GetUninstallString(): String;
var
  sUnInstPath: String;
  sUnInstallString: String;
begin
  sUnInstPath := 'Software\Microsoft\Windows\CurrentVersion\Uninstall\wxCrafter_is1';
  sUnInstallString := '';
  if not RegQueryStringValue(HKLM, sUnInstPath, 'UninstallString', sUnInstallString) then
    RegQueryStringValue(HKCU, sUnInstPath, 'UninstallString', sUnInstallString);
  Result := sUnInstallString;
end;

function UnInstallOldVersion(): Integer;
var
    sUnInstallString: String;
    sUnInstallStringOld: String;
    iResultCode: Integer;

begin
    // Return Values:
    // 1 - uninstall string is empty
    // 2 - error executing the UnInstallString
    // 3 - successfully executed the UnInstallString

    // default return value
    Result := 0;

    sUnInstallString    := GetUninstallString();
    if sUnInstallString <> '' then begin
        sUnInstallString := RemoveQuotes(sUnInstallString);
    if Exec(sUnInstallString, '/SILENT /NORESTART /SUPPRESSMSGBOXES ','', SW_HIDE, ewWaitUntilTerminated, iResultCode) then
        Result := 3
    else
        Result := 2;
    end else
        Result := 1;
end;

function GetwxCrafterInstallPath(): String;
var
    sRegKey: String;
    swxCrafterPath: String;
begin
    sRegKey := 'Software\wxcrafter\settings';
    swxCrafterPath := '';
    if not RegQueryStringValue(HKLM, sRegKey, 'InstallPath', swxCrafterPath) then
        RegQueryStringValue(HKCU, sRegKey, 'InstallPath', swxCrafterPath);
    Result := swxCrafterPath;
end;

function UnInstallVersion6(): Integer;
var
    swxCrafterPath: String;

begin
    if GetwxCrafterInstallPath() <> '' then
    BEGIN
        // Uninstall wxcrafter 6.X
        swxCrafterPath := GetwxCrafterInstallPath()

        // Delete the following folders:
        DelTree(swxCrafterPath + '\plugins', True, True, True )
        DelTree(swxCrafterPath + '\lexers', True, True, True)
        DelTree(swxCrafterPath + '\config', True, True, True)
        DelTree(swxCrafterPath + '\dics', True, True, True)
        DelTree(swxCrafterPath + '\locale', True, True, True)

        // Clear the content of wxCrafter installation folder (*.exe, *.zip, *.dll)
        DelTree(swxCrafterPath + '\*.exe', False, True, False)
        DelTree(swxCrafterPath + '\*.zip', False, True, False)
        DelTree(swxCrafterPath + '\*.dll', False, True, False)
        DelTree(swxCrafterPath + '\*.RPT', False, True, False)
        DelTree(swxCrafterPath + '\*.ini', False, True, False)
        DelTree(swxCrafterPath + '\*.html', False, True, False)
        DelTree(swxCrafterPath + '\*.dat', False, True, False)

        if MsgBox('Would you like to keep your local settings?', mbConfirmation, MB_YESNO or MB_DEFBUTTON1) = IDNO
        then
        BEGIN
            DelTree(ExpandConstant('{userappdata}') + '\wxcrafter', True, True, True)
        END
    END
end;

function IsUpgrade(): Boolean;
begin
  Result := (GetUninstallString() <> '');
end;

function GetMinGWInstallLocation(): String;
var
    sMinGWPath: String;
    sMinGWPathLocation: String;
begin
    sMinGWPath := 'Software\wxcrafter\settings';
    sMinGWPathLocation := '';
    if not RegQueryStringValue(HKLM, sMinGWPath, 'MinGW', sMinGWPathLocation) then
        RegQueryStringValue(HKCU, sMinGWPath, 'MinGW', sMinGWPathLocation);
    Result := sMinGWPathLocation;
end;

//-------------------------------------------------------
// Backup MinGW installation before uninstalling wxCrafter
//-------------------------------------------------------
//procedure BackupMinGW();
//var
//    sMinGWLocation: String;
//    sTempFolder: String;
//    sMinGWBackupPath: String;
//    sMinGWDrive: String;
//
//begin
//    bMinGWBackedUp := False;
//    sMinGWLocation := GetMinGWInstallLocation();
//    if sMinGWLocation <> '' then
//    begin
//        sMinGWFolderName := ExtractFileName(sMinGWLocation);
//        sMinGWDrive := ExtractFileDrive(sMinGWLocation);
//        sMinGWBackupPath := sMinGWDrive + '\' + sMinGWFolderName + '.backup'; // Rename the folder so it won't get deleted
//        bMinGWBackedUp := RenameFile(sMinGWLocation, sMinGWBackupPath);
//    end;
//end;

//----------------------------------------------------
// Restore MinGW from a previously back up
//----------------------------------------------------
//procedure RestoreMinGW();
//var
//    sMinGWLocation: String;
//    sTempFolder: String;
//    sMinGWBackupPath: String;
//    sMinGWNewLocation: String;
//begin
//    sMinGWLocation := GetMinGWInstallLocation();
//    sMinGWNewLocation := sMinGWLocation; // By default restore to the old location
//    if (sMinGWLocation <> '') AND (bMinGWBackedUp = True) then
//    BEGIN
//        sMinGWBackupPath := GetEnv('TEMP') + '\' + sMinGWFolderName;
//        if not CreateDir(sMinGWNewLocation) then
//        BEGIN
//            // Could not create the restore location, prompt the user
//            sMinGWNewLocation := ''
//            if BrowseForFolder('Could not restore MinGW to its previous location' + #13#10 + 'Please select a new location to restore MinGW (Setup will restore it into a separate folder):', sMinGWNewLocation, False) = True then
//            BEGIN
//                sMinGWNewLocation := sMinGWNewLocation + sMinGWFolderName;
//            END
//        END else BEGIN
//            // We can safely restore the folder
//            RemoveDir(sMinGWNewLocation)
//        END
//    END
//
//	if sMinGWNewLocation <> '' then
//    BEGIN
//        RenameFile(sMinGWBackupPath, sMinGWNewLocation)
//    END
//end;

procedure CurStepChanged(CurStep: TSetupStep);
var
  ResultCode: Integer;
begin
    case CurStep of
    ssInstall:
        begin
          if (IsUpgrade()) then
            begin
                // Uninstall wxCrafter
                UnInstallVersion6()
            end;
        end;
    end;
end;
