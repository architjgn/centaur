#ifndef CENTAURAPP_H
#define CENTAURAPP_H

#include "MooseApp.h"

class CentaurApp;

template<>
InputParameters validParams<CentaurApp>();

class CentaurApp : public MooseApp
{
public:
  CentaurApp(InputParameters parameters);
  virtual ~CentaurApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CENTAURAPP_H */
