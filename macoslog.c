// macoslog.c: A simple extension to log to the macOS Unified Logging System.
// Based on Ned Batchelder's "A Whirlwind Excursion through Python C Extensions"
// (http://nedbatchelder.com/text/whirlext.html)

#include "Python.h"
#include <os/log.h>


static PyObject *
write_log(PyObject *self, PyObject *args)
{	
	const char *our_subsystem;
	const char *our_category;
	const char *log_string;
	os_log_t our_log;
	
	if (!PyArg_ParseTuple(args, "sss:write_log", &our_subsystem, &our_category, &log_string))
	{
		return NULL;
	}
	
	our_log = os_log_create(our_subsystem, our_category);
	os_log(our_log,"%{public}s", log_string);
	return Py_BuildValue("");
	
}

// Module functions table.

static PyMethodDef
module_functions[] = {
    { "write_log", write_log, METH_VARARGS, "Write an entry with an object/subsystem/category." },
    { NULL }
};

// This function is called to initialize the module.

void
initmacoslog(void)
{
    Py_InitModule3("macoslog", module_functions, "This is an extension to log to the macOS Unified Logging system.");
}
