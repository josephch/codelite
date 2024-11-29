#include "ThemeImporterErrorlist.hpp"

#include "clColours.h"
#include "drawingutils.h"

ThemeImporterErrorlist::ThemeImporterErrorlist()
{
    SetFileExtensions("*.log");
    m_langName = "errorlist";
}

ThemeImporterErrorlist::~ThemeImporterErrorlist() {}
LexerConf::Ptr_t ThemeImporterErrorlist::Import(const wxFileName& theme_file)
{
    LexerConf::Ptr_t lexer = InitializeImport(theme_file, m_langName, wxSTC_LEX_ERRORLIST);
    bool is_dark = DrawingUtils::IsDark(m_editor.bg_colour);

    AddProperty(lexer, wxSTC_ERR_DEFAULT, "Default", m_editor);
    AddProperty(lexer, wxSTC_ERR_PYTHON, "Python error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_GCC, "GCC like error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_MS, "MSVC error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_CMD, "CMD error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_BORLAND, "Borland error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_PERL, "Perl error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_NET, ".NET error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_LUA, "LUA error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_CTAG, "CTags line", clColours::Cyan(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_DIFF_CHANGED, "Diff line changed", clColours::Yellow(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_DIFF_ADDITION, "Diff line added", clColours::Green(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_DIFF_DELETION, "Diff line deleted", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_DIFF_MESSAGE, "Diff line message", clColours::Cyan(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_PHP, "PHP error message", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ELF, "Essential Lahey Fortran error message", clColours::Red(is_dark),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_IFC, "Intel Fortran Compiler error/warning message", clColours::Red(is_dark),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_IFORT, "Intel Fortran Compiler v8.0 error/warning message", clColours::Red(is_dark),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ABSF, "Absoft Pro Fortran 90/95 v8.2 error and/or warning message",
                clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_TIDY, "HTML tidy style", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_JAVA_STACK, "Java stack", clColours::Cyan(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_VALUE, "Value", m_editor);
    AddProperty(lexer, wxSTC_ERR_GCC_INCLUDED_FROM, "GCC 'included from'", clColours::Grey(is_dark),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ESCSEQ, "ANSI escape sequence", m_editor);
    AddProperty(lexer, wxSTC_ERR_ESCSEQ_UNKNOWN, "ANSI escape sequence unknown", clColours::Red(is_dark),
                m_editor.bg_colour);

#if wxCHECK_VERSION(3, 3, 0)
    AddProperty(lexer, wxSTC_ERR_GCC_EXCERPT, "GCC code excerpt and pointer to issue", clColours::Cyan(is_dark),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_BASH, "Bash diagnostic line", clColours::Red(is_dark), m_editor.bg_colour);
#endif

    AddProperty(lexer, wxSTC_ERR_ES_BLACK, "ANSI escape black", clColours::Black(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_RED, "ANSI escape red", clColours::Red(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_GREEN, "ANSI escape green", clColours::Green(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_BROWN, "ANSI escape brown", clColours::Yellow(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_BLUE, "ANSI escape blue", clColours::Blue(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_MAGENTA, "ANSI escape magenta", clColours::Magenta(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_CYAN, "ANSI escape cyan", clColours::Cyan(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_GRAY, "ANSI escape grey", clColours::Grey(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_YELLOW, "ANSI escape yellow", clColours::Yellow(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_DARK_GRAY, "ANSI escape dark grey", clColours::Grey(is_dark), m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_BRIGHT_RED, "ANSI escape bright red", clColours::Red(is_dark, true),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_BRIGHT_GREEN, "ANSI escape bright green", clColours::Green(is_dark, true),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_BRIGHT_BLUE, "ANSI escape bright blue", clColours::Blue(is_dark, true),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_BRIGHT_MAGENTA, "ANSI escape bright magenta", clColours::Magenta(is_dark, true),
                m_editor.bg_colour);
    AddProperty(lexer, wxSTC_ERR_ES_BRIGHT_CYAN, "ANSI escape bright cyan", clColours::Cyan(is_dark, true),
                m_editor.bg_colour);
    FinalizeImport(lexer);
    return lexer;
}