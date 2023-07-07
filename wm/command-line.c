//
// Created by dingjing on 23-7-7.
//

#include "command-line.h"

#include <glib.h>
#include <glib/gi18n.h>

#include "common/log.h"


static GOptionEntry entries[] =
    {
        {"replace",     0,      G_OPTION_FLAG_NONE, G_OPTION_ARG_NONE,  &gReplaceWM,    N_("Replace current window manager"),   NULL},
        {"version",     0,      G_OPTION_FLAG_NONE, G_OPTION_ARG_NONE,  &gVersion,      N_("Print version information"),        NULL},
        G_OPTION_ENTRY_NULL
    };


void parse_commandline(int argc, char* argv[])
{
    g_autoptr(GError) error = NULL;
    GOptionContext* ctx = g_option_context_new ("");

    g_option_context_add_main_entries (ctx, entries, APP_VERSION);
    if (!g_option_context_parse (ctx, &argc, &argv, &error)) {
        LOG_ERROR(_("parse commandline error!"));
    }

    LOG_DEBUG(_("commandline parsed:\n"
                " replace: %s"), (gReplaceWM ? "true" : "false")
                );

    g_option_context_free (ctx);

    if (gVersion) {
        fprintf (stdout, APP_NAME ": %s\n", APP_VERSION);
        exit (0);
    }
}

void load_configure(const char *confFile)
{

}
