#include "StdAfx.h"

#include <stdlib.h>
#include <string>

#include "jx.h"

void nullCallback(JXResult *results, int argc) {
  // do nothing
}

void showMsg(JXResult *results, int argc) {
  static int g_count = 0;
  static FILE* fp = NULL;
  if (fp == NULL) {
	  fp = fopen("log.txt", "w");
  }
  JXValue* val = &results[0];
  std::string str = JX_GetString(val);
  fprintf(fp, "count %d msg %s\n", g_count, str.c_str());
  g_count += 1;
}

void JSEngineRun(char* executable) {
  JX_Initialize(executable, nullCallback);
  JX_InitializeNewEngine();

  char *contents = "process.natives.showMsg('a');";
  JX_DefineMainFile(contents);

  JX_DefineExtension("showMsg", showMsg);
  JX_StartEngine();
  while (JX_LoopOnce());

  JXValue ret_val;
  JX_Evaluate("process.natives.showMsg('b');", "eval", &ret_val);
  JX_Free(&ret_val);
  while (JX_LoopOnce());
  JX_StopEngine();
}