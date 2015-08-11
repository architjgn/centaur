#include "CentaurApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<CentaurApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

CentaurApp::CentaurApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  CentaurApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  CentaurApp::associateSyntax(_syntax, _action_factory);
}

CentaurApp::~CentaurApp()
{
}

// External entry point for dynamic application loading
extern "C" void CentaurApp__registerApps() { CentaurApp::registerApps(); }
void
CentaurApp::registerApps()
{
  registerApp(CentaurApp);
}

// External entry point for dynamic object registration
extern "C" void CentaurApp__registerObjects(Factory & factory) { CentaurApp::registerObjects(factory); }
void
CentaurApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void CentaurApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CentaurApp::associateSyntax(syntax, action_factory); }
void
CentaurApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
