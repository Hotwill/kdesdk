/**
 * Copyright (C)  2005  Jeroen Wijnhout <Jeroen.Wijnhout@kdemail.net>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <kdebug.h>
#include <kapplication.h>
#include <kglobal.h>
#include <kcomponentdata.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocale.h>

#include "runnergui.h"

static const char description[] =
    I18N_NOOP("A command-line application that can be used to run KUnitTest modules.");

static const char version[] = "0.1";


int main( int argc, char **argv )
{    
    KComponentData componentData("modrunner");

    KAboutData about("KUnitTestModRunner", 0, ki18n("KUnitTestModRunner"), version, ki18n(description),
                     KAboutData::License_BSD, ki18n("(C) 2005 Jeroen Wijnhout"), KLocalizedString(), 0,
                     "Jeroen.Wijnhout@kdemail.net");

    KCmdLineArgs::init(argc, argv, &about);

    KCmdLineOptions options;
    options.add("query [regexp]", ki18n("Only run modules which filename match the regexp."), "^kunittest_.*\\.la$");
    options.add("folder [folder]", ki18n("Only run tests modules which are found in the folder. Use the query option to select modules."), ".");
    options.add("enable-dbgcap", ki18n("Enables debug capturing. You typically use this option when you use the GUI."));
    KCmdLineArgs::addCmdLineOptions( options );
    KCmdLineArgs *args = KCmdLineArgs::parsedArgs();

    KUnitTest::Runner::loadModules(args->getOption("folder"), args->getOption("query"));
    KUnitTest::Runner::setDebugCapturingEnabled(args->isSet("enable-dbgcap"));

    KApplication app;

    KUnitTest::RunnerGUI runner(0);
    runner.show();
    app.setMainWidget(&runner);

    return app.exec();
}
