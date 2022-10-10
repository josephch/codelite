#include "PlatformCommon.hpp"

#include "Platform.hpp"
#include "file_logger.h"
#include "procutils.h"

#include <wx/arrstr.h>

bool PlatformCommon::WhichWithVersion(const wxString& command, const std::vector<int>& versions,
                                      wxString* command_fullpath)
{
    wxArrayString names;
    names.reserve(versions.size() + 1);

    for(auto ver : versions) {
        names.Add(wxString() << command << "-" << ver);
    }
    names.Add(command);
    for(const wxString& name : names) {
        if(PLATFORM::Which(name, command_fullpath)) {
            return true;
        }
    }
    return false;
}

/// Locate rustup bin folder
/// the path is set to:
/// $HOME/.rustup/TOOLCHAIN-NAME/bin
bool PlatformCommon::FindRustupToolchainBinDir(wxString* rustup_bin_dir)
{
#ifdef __WXMSW__
    return false;
#else
    wxString homedir;
    PLATFORM::FindHomeDir(&homedir);

    wxString rustup_exe;
    rustup_exe << homedir << "/.cargo/bin/rustup";
    if(!wxFileName::FileExists(rustup_exe)) {
        return false;
    }

    // locate the default toolchain
    wxString toolchain_name = ProcUtils::GrepCommandOutput({ rustup_exe, "toolchain", "list" }, "(default)");
    toolchain_name = toolchain_name.BeforeLast('(');
    toolchain_name.Trim().Trim(false);
    if(toolchain_name.empty()) {
        return false;
    }

    // build the path
    *rustup_bin_dir << homedir << "/.rustup/toolchains/" << toolchain_name << "/bin";
    clDEBUG() << "Rust toolchain path:" << *rustup_bin_dir << endl;
    return true;
#endif
}
