#include "ns3module.h"
static PyMethodDef ndnSIM_ndn_name_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


std::map<void*, PyObject*> PyNs3NdnNameComponent_wrapper_registry;


static int
_wrap_PyNs3NdnNameComponent__tp_init__0(PyNs3NdnNameComponent *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3NdnNameComponent *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NdnNameComponent_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ndn::name::Component(*((PyNs3NdnNameComponent *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3NdnNameComponent__tp_init__1(PyNs3NdnNameComponent *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ndn::name::Component();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3NdnNameComponent__tp_init(PyNs3NdnNameComponent *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3NdnNameComponent__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnNameComponent__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3NdnNameComponent_fromEscapedString(PyNs3NdnNameComponent *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *uri;
    Py_ssize_t uri_len;
    std::string uri_std;
    const char *keywords[] = {"uri", NULL};
    PyNs3NdnNameComponent *py_Component;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &uri, &uri_len)) {
        return NULL;
    }
    uri_std = std::string(uri, uri_len);
    ns3::ndn::name::Component retval = self->obj->fromEscapedString(uri_std);
    py_Component = PyObject_New(PyNs3NdnNameComponent, &PyNs3NdnNameComponent_Type);
    py_Component->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Component->obj = new ns3::ndn::name::Component(retval);
    PyNs3NdnNameComponent_wrapper_registry[(void *) py_Component->obj] = (PyObject *) py_Component;
    py_retval = Py_BuildValue((char *) "N", py_Component);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNameComponent_fromNumber(PyNs3NdnNameComponent *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint64_t number;
    const char *keywords[] = {"number", NULL};
    PyNs3NdnNameComponent *py_Component;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "K", (char **) keywords, &number)) {
        return NULL;
    }
    ns3::ndn::name::Component retval = self->obj->fromNumber(number);
    py_Component = PyObject_New(PyNs3NdnNameComponent, &PyNs3NdnNameComponent_Type);
    py_Component->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Component->obj = new ns3::ndn::name::Component(retval);
    PyNs3NdnNameComponent_wrapper_registry[(void *) py_Component->obj] = (PyObject *) py_Component;
    py_retval = Py_BuildValue((char *) "N", py_Component);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNameComponent_fromNumberWithMarker(PyNs3NdnNameComponent *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint64_t number;
    int marker;
    const char *keywords[] = {"number", "marker", NULL};
    PyNs3NdnNameComponent *py_Component;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Ki", (char **) keywords, &number, &marker)) {
        return NULL;
    }
    if (marker > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    ns3::ndn::name::Component retval = self->obj->fromNumberWithMarker(number, marker);
    py_Component = PyObject_New(PyNs3NdnNameComponent, &PyNs3NdnNameComponent_Type);
    py_Component->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Component->obj = new ns3::ndn::name::Component(retval);
    PyNs3NdnNameComponent_wrapper_registry[(void *) py_Component->obj] = (PyObject *) py_Component;
    py_retval = Py_BuildValue((char *) "N", py_Component);
    return py_retval;
}


static PyObject*
_wrap_PyNs3NdnNameComponent__copy__(PyNs3NdnNameComponent *self)
{

    PyNs3NdnNameComponent *py_copy;
    py_copy = PyObject_New(PyNs3NdnNameComponent, &PyNs3NdnNameComponent_Type);
    py_copy->obj = new ns3::ndn::name::Component(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3NdnNameComponent_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3NdnNameComponent_methods[] = {
    {(char *) "fromEscapedString", (PyCFunction) _wrap_PyNs3NdnNameComponent_fromEscapedString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "fromNumber", (PyCFunction) _wrap_PyNs3NdnNameComponent_fromNumber, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "fromNumberWithMarker", (PyCFunction) _wrap_PyNs3NdnNameComponent_fromNumberWithMarker, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3NdnNameComponent__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNameComponent__tp_dealloc(PyNs3NdnNameComponent *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNameComponent_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNameComponent_wrapper_registry.end()) {
        PyNs3NdnNameComponent_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::name::Component *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3NdnNameComponent__tp_str(PyNs3NdnNameComponent *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3NdnNameComponent__tp_richcompare (PyNs3NdnNameComponent *PYBINDGEN_UNUSED(self), PyNs3NdnNameComponent *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNameComponent_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        if (*self->obj < *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_LE:
        if (*self->obj <= *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_EQ:
        if (*self->obj == *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_NE:
        if (*self->obj != *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_GE:
        if (*self->obj >= *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_GT:
        if (*self->obj > *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnNameComponent_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.name.Component",            /* tp_name */
    sizeof(PyNs3NdnNameComponent),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNameComponent__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)_wrap_PyNs3NdnNameComponent__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNameComponent__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNameComponent_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNameComponent__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef ndnSIM_ndn_name_moduledef = {
    PyModuleDef_HEAD_INIT,
    "ndnSIM.ndn.name",
    NULL,
    -1,
    ndnSIM_ndn_name_functions,
};
#endif

static PyObject *
initndnSIM_ndn_name(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&ndnSIM_ndn_name_moduledef);
    #else
    m = Py_InitModule3((char *) "ndnSIM.ndn.name", ndnSIM_ndn_name_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "_PyNs3NdnNameComponent_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNameComponent_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::name::Component' class */
    if (PyType_Ready(&PyNs3NdnNameComponent_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Component", (PyObject *) &PyNs3NdnNameComponent_Type);
    return m;
}
static PyMethodDef ndnSIM_ndn_nfd_fib_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


std::map<void*, PyObject*> PyNs3NdnNfdFibEntry_wrapper_registry;

static int
_wrap_PyNs3NdnNfdFibEntry__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'Entry' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnNfdFibEntry_getNextHops(PyNs3NdnNfdFibEntry *self)
{
    PyObject *py_retval;
    PyNs3NdnNfdFibNextHopList *py_NextHopList;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    ns3::ndn::nfd::fib::NextHopList const & retval = self->obj->getNextHops();
    wrapper_lookup_iter = PyNs3NdnNfdFibNextHopList_wrapper_registry.find((void *) (&retval));
    if (wrapper_lookup_iter == PyNs3NdnNfdFibNextHopList_wrapper_registry.end()) {
        py_NextHopList = NULL;
    } else {
        py_NextHopList = (PyNs3NdnNfdFibNextHopList *) wrapper_lookup_iter->second;
        Py_INCREF(py_NextHopList);
    }
    
    if (py_NextHopList == NULL) {
        py_NextHopList = PyObject_New(PyNs3NdnNfdFibNextHopList, &PyNs3NdnNfdFibNextHopList_Type);
        py_NextHopList->obj = (ns3::ndn::nfd::fib::NextHopList *) ((&retval));
        py_NextHopList->flags = PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED;
        PyNs3NdnNfdFibNextHopList_wrapper_registry[(void *) py_NextHopList->obj] = (PyObject *) py_NextHopList;
    }
    py_retval = Py_BuildValue((char *) "N", py_NextHopList);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNfdFibEntry_getPrefix(PyNs3NdnNfdFibEntry *self)
{
    PyObject *py_retval;
    PyNs3NdnName *py_Name;
    
    ns3::ndn::Name const & retval = self->obj->getPrefix();
    py_Name = PyObject_New(PyNs3NdnName, &PyNs3NdnName_Type);
    py_Name->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Name->obj = new ns3::ndn::Name(retval);
    PyNs3NdnName_wrapper_registry[(void *) py_Name->obj] = (PyObject *) py_Name;
    py_retval = Py_BuildValue((char *) "N", py_Name);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNfdFibEntry_hasNextHops(PyNs3NdnNfdFibEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->hasNextHops();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdFibEntry_methods[] = {
    {(char *) "getNextHops", (PyCFunction) _wrap_PyNs3NdnNfdFibEntry_getNextHops, METH_NOARGS, NULL },
    {(char *) "getPrefix", (PyCFunction) _wrap_PyNs3NdnNfdFibEntry_getPrefix, METH_NOARGS, NULL },
    {(char *) "hasNextHops", (PyCFunction) _wrap_PyNs3NdnNfdFibEntry_hasNextHops, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdFibEntry__tp_dealloc(PyNs3NdnNfdFibEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdFibEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNfdFibEntry_wrapper_registry.end()) {
        PyNs3NdnNfdFibEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::nfd::fib::Entry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdFibEntry__tp_richcompare (PyNs3NdnNfdFibEntry *PYBINDGEN_UNUSED(self), PyNs3NdnNfdFibEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdFibEntry_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnNfdFibEntry_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.fib.Entry",            /* tp_name */
    sizeof(PyNs3NdnNfdFibEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdFibEntry__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdFibEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdFibEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdFibEntry__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnNfdFibNextHop_wrapper_registry;

static int
_wrap_PyNs3NdnNfdFibNextHop__tp_init(PyNs3NdnNfdFibNextHop *self, PyObject *args, PyObject *kwargs)
{
    PyNs3NdnFace *face;
    ::std::shared_ptr< ns3::ndn::Face > face_ptr;
    const char *keywords[] = {"face", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NdnFace_Type, &face)) {
        return -1;
    }
    if (face) { face_ptr = face->obj; }
    self->obj = new ns3::ndn::nfd::fib::NextHop(face_ptr);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3NdnNfdFibNextHop_getFace(PyNs3NdnNfdFibNextHop *self)
{
    PyObject *py_retval;
    std::shared_ptr< ns3::ndn::Face > retval;
    PyNs3NdnFace *py_Face;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    retval = self->obj->getFace();
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3NdnFace_wrapper_registry.find((void *) retval.get());
    if (wrapper_lookup_iter == PyNs3NdnFace_wrapper_registry.end()) {
        py_Face = NULL;
    } else {
        py_Face = (PyNs3NdnFace *) wrapper_lookup_iter->second;
        Py_INCREF(py_Face);
    }
    
    if (py_Face == NULL) {
        py_Face = PyObject_New(PyNs3NdnFace, &PyNs3NdnFace_Type);
        new(&py_Face->obj) ::std::shared_ptr< ns3::ndn::Face >;
        py_Face->obj = retval;
        py_Face->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3NdnFace_wrapper_registry[(void *) py_Face->obj.get()] = (PyObject *) py_Face;
    }
    py_retval = Py_BuildValue((char *) "N", py_Face);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNfdFibNextHop_setCost(PyNs3NdnNfdFibNextHop *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint64_t cost;
    const char *keywords[] = {"cost", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "K", (char **) keywords, &cost)) {
        return NULL;
    }
    self->obj->setCost(cost);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNfdFibNextHop_getCost(PyNs3NdnNfdFibNextHop *self)
{
    PyObject *py_retval;
    uint64_t retval;
    
    retval = self->obj->getCost();
    py_retval = Py_BuildValue((char *) "K", retval);
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdFibNextHop_methods[] = {
    {(char *) "getFace", (PyCFunction) _wrap_PyNs3NdnNfdFibNextHop_getFace, METH_NOARGS, NULL },
    {(char *) "setCost", (PyCFunction) _wrap_PyNs3NdnNfdFibNextHop_setCost, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "getCost", (PyCFunction) _wrap_PyNs3NdnNfdFibNextHop_getCost, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdFibNextHop__tp_dealloc(PyNs3NdnNfdFibNextHop *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdFibNextHop_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNfdFibNextHop_wrapper_registry.end()) {
        PyNs3NdnNfdFibNextHop_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::nfd::fib::NextHop *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdFibNextHop__tp_richcompare (PyNs3NdnNfdFibNextHop *PYBINDGEN_UNUSED(self), PyNs3NdnNfdFibNextHop *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdFibNextHop_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnNfdFibNextHop_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.fib.NextHop",            /* tp_name */
    sizeof(PyNs3NdnNfdFibNextHop),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdFibNextHop__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdFibNextHop__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdFibNextHop_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdFibNextHop__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnNfdFibNextHopList_wrapper_registry;

static int
_wrap_PyNs3NdnNfdFibNextHopList__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'NextHopList' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnNfdFibNextHopList_size(PyNs3NdnNfdFibNextHopList *self)
{
    PyObject *py_retval;
    size_t retval;
    
    retval = self->obj->size();
    py_retval = Py_BuildValue((char *) "K", ((unsigned PY_LONG_LONG) retval));
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdFibNextHopList_methods[] = {
    {(char *) "size", (PyCFunction) _wrap_PyNs3NdnNfdFibNextHopList_size, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdFibNextHopList__tp_dealloc(PyNs3NdnNfdFibNextHopList *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdFibNextHopList_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNfdFibNextHopList_wrapper_registry.end()) {
        PyNs3NdnNfdFibNextHopList_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::nfd::fib::NextHopList *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdFibNextHopList__tp_richcompare (PyNs3NdnNfdFibNextHopList *PYBINDGEN_UNUSED(self), PyNs3NdnNfdFibNextHopList *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdFibNextHopList_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}


static void
PyNs3NdnNfdFibNextHopList_Iter__tp_clear(PyNs3NdnNfdFibNextHopList_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
PyNs3NdnNfdFibNextHopList_Iter__tp_traverse(PyNs3NdnNfdFibNextHopList_Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_PyNs3NdnNfdFibNextHopList_Iter__tp_dealloc(PyNs3NdnNfdFibNextHopList_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_PyNs3NdnNfdFibNextHopList__tp_iter(PyNs3NdnNfdFibNextHopList *self)
{
    PyNs3NdnNfdFibNextHopList_Iter *iter = PyObject_GC_New(PyNs3NdnNfdFibNextHopList_Iter, &PyNs3NdnNfdFibNextHopList_IterType);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new ns3::ndn::nfd::fib::NextHopList::const_iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_PyNs3NdnNfdFibNextHopList_Iter__tp_iter(PyNs3NdnNfdFibNextHopList_Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_PyNs3NdnNfdFibNextHopList_Iter__tp_iternext(PyNs3NdnNfdFibNextHopList_Iter *self)
{
    PyObject *py_retval;
    ns3::ndn::nfd::fib::NextHopList::const_iterator iter;
    PyNs3NdnNfdFibNextHop *py_NextHop;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    wrapper_lookup_iter = PyNs3NdnNfdFibNextHop_wrapper_registry.find((void *) (&(*iter)));
    if (wrapper_lookup_iter == PyNs3NdnNfdFibNextHop_wrapper_registry.end()) {
        py_NextHop = NULL;
    } else {
        py_NextHop = (PyNs3NdnNfdFibNextHop *) wrapper_lookup_iter->second;
        Py_INCREF(py_NextHop);
    }
    
    if (py_NextHop == NULL) {
        py_NextHop = PyObject_New(PyNs3NdnNfdFibNextHop, &PyNs3NdnNfdFibNextHop_Type);
        py_NextHop->obj = (ns3::ndn::nfd::fib::NextHop *) ((&(*iter)));
        py_NextHop->flags = PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED;
        PyNs3NdnNfdFibNextHop_wrapper_registry[(void *) py_NextHop->obj] = (PyObject *) py_NextHop;
    }
    py_retval = Py_BuildValue((char *) "N", py_NextHop);
    return py_retval;
}
PyTypeObject PyNs3NdnNfdFibNextHopList_IterType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.fib.NextHopListIter",            /* tp_name */
    sizeof(PyNs3NdnNfdFibNextHopList_Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdFibNextHopList_Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3NdnNfdFibNextHopList_Iter__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3NdnNfdFibNextHopList_Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnNfdFibNextHopList_Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_PyNs3NdnNfdFibNextHopList_Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject PyNs3NdnNfdFibNextHopList_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.fib.NextHopList",            /* tp_name */
    sizeof(PyNs3NdnNfdFibNextHopList),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdFibNextHopList__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdFibNextHopList__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnNfdFibNextHopList__tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdFibNextHopList_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdFibNextHopList__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef ndnSIM_ndn_nfd_fib_moduledef = {
    PyModuleDef_HEAD_INIT,
    "ndnSIM.ndn.nfd.fib",
    NULL,
    -1,
    ndnSIM_ndn_nfd_fib_functions,
};
#endif

static PyObject *
initndnSIM_ndn_nfd_fib(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&ndnSIM_ndn_nfd_fib_moduledef);
    #else
    m = Py_InitModule3((char *) "ndnSIM.ndn.nfd.fib", ndnSIM_ndn_nfd_fib_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdFibEntry_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdFibEntry_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::fib::Entry' class */
    if (PyType_Ready(&PyNs3NdnNfdFibEntry_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Entry", (PyObject *) &PyNs3NdnNfdFibEntry_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdFibNextHop_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdFibNextHop_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::fib::NextHop' class */
    if (PyType_Ready(&PyNs3NdnNfdFibNextHop_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "NextHop", (PyObject *) &PyNs3NdnNfdFibNextHop_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdFibNextHopList_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdFibNextHopList_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::fib::NextHopList' class */
    if (PyType_Ready(&PyNs3NdnNfdFibNextHopList_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "NextHopList", (PyObject *) &PyNs3NdnNfdFibNextHopList_Type);
    /* Register the 'ns3::ndn::nfd::fib::NextHopList' class iterator*/
    if (PyType_Ready(&PyNs3NdnNfdFibNextHopList_IterType)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "NextHopListIter", (PyObject *) &PyNs3NdnNfdFibNextHopList_IterType);
    return m;
}
static PyMethodDef ndnSIM_ndn_nfd_pit_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


std::map<void*, PyObject*> PyNs3NdnNfdPitEntry_wrapper_registry;

static int
_wrap_PyNs3NdnNfdPitEntry__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'Entry' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnNfdPitEntry_getInterest(PyNs3NdnNfdPitEntry *self)
{
    PyObject *py_retval;
    PyNs3NdnInterest *py_Interest;
    
    ns3::ndn::Interest const & retval = self->obj->getInterest();
    py_Interest = PyObject_New(PyNs3NdnInterest, &PyNs3NdnInterest_Type);
    py_Interest->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Interest->obj = new ns3::ndn::Interest(retval);
    PyNs3NdnInterest_wrapper_registry[(void *) py_Interest->obj] = (PyObject *) py_Interest;
    py_retval = Py_BuildValue((char *) "N", py_Interest);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNfdPitEntry_getName(PyNs3NdnNfdPitEntry *self)
{
    PyObject *py_retval;
    PyNs3NdnName *py_Name;
    
    ns3::ndn::Name const & retval = self->obj->getName();
    py_Name = PyObject_New(PyNs3NdnName, &PyNs3NdnName_Type);
    py_Name->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Name->obj = new ns3::ndn::Name(retval);
    PyNs3NdnName_wrapper_registry[(void *) py_Name->obj] = (PyObject *) py_Name;
    py_retval = Py_BuildValue((char *) "N", py_Name);
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdPitEntry_methods[] = {
    {(char *) "getInterest", (PyCFunction) _wrap_PyNs3NdnNfdPitEntry_getInterest, METH_NOARGS, NULL },
    {(char *) "getName", (PyCFunction) _wrap_PyNs3NdnNfdPitEntry_getName, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdPitEntry__tp_dealloc(PyNs3NdnNfdPitEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdPitEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNfdPitEntry_wrapper_registry.end()) {
        PyNs3NdnNfdPitEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::nfd::pit::Entry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdPitEntry__tp_richcompare (PyNs3NdnNfdPitEntry *PYBINDGEN_UNUSED(self), PyNs3NdnNfdPitEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdPitEntry_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnNfdPitEntry_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.pit.Entry",            /* tp_name */
    sizeof(PyNs3NdnNfdPitEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdPitEntry__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdPitEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdPitEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdPitEntry__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef ndnSIM_ndn_nfd_pit_moduledef = {
    PyModuleDef_HEAD_INIT,
    "ndnSIM.ndn.nfd.pit",
    NULL,
    -1,
    ndnSIM_ndn_nfd_pit_functions,
};
#endif

static PyObject *
initndnSIM_ndn_nfd_pit(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&ndnSIM_ndn_nfd_pit_moduledef);
    #else
    m = Py_InitModule3((char *) "ndnSIM.ndn.nfd.pit", ndnSIM_ndn_nfd_pit_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdPitEntry_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdPitEntry_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::pit::Entry' class */
    if (PyType_Ready(&PyNs3NdnNfdPitEntry_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Entry", (PyObject *) &PyNs3NdnNfdPitEntry_Type);
    return m;
}
static PyMethodDef ndnSIM_ndn_nfd_cs_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


std::map<void*, PyObject*> PyNs3NdnNfdCsEntry_wrapper_registry;

static int
_wrap_PyNs3NdnNfdCsEntry__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'Entry' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnNfdCsEntry_getName(PyNs3NdnNfdCsEntry *self)
{
    PyObject *py_retval;
    PyNs3NdnName *py_Name;
    
    ns3::ndn::Name const & retval = self->obj->getName();
    py_Name = PyObject_New(PyNs3NdnName, &PyNs3NdnName_Type);
    py_Name->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Name->obj = new ns3::ndn::Name(retval);
    PyNs3NdnName_wrapper_registry[(void *) py_Name->obj] = (PyObject *) py_Name;
    py_retval = Py_BuildValue((char *) "N", py_Name);
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdCsEntry_methods[] = {
    {(char *) "getName", (PyCFunction) _wrap_PyNs3NdnNfdCsEntry_getName, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdCsEntry__tp_dealloc(PyNs3NdnNfdCsEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdCsEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNfdCsEntry_wrapper_registry.end()) {
        PyNs3NdnNfdCsEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::nfd::cs::Entry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdCsEntry__tp_richcompare (PyNs3NdnNfdCsEntry *PYBINDGEN_UNUSED(self), PyNs3NdnNfdCsEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdCsEntry_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnNfdCsEntry_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.cs.Entry",            /* tp_name */
    sizeof(PyNs3NdnNfdCsEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdCsEntry__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdCsEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdCsEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdCsEntry__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef ndnSIM_ndn_nfd_cs_moduledef = {
    PyModuleDef_HEAD_INIT,
    "ndnSIM.ndn.nfd.cs",
    NULL,
    -1,
    ndnSIM_ndn_nfd_cs_functions,
};
#endif

static PyObject *
initndnSIM_ndn_nfd_cs(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&ndnSIM_ndn_nfd_cs_moduledef);
    #else
    m = Py_InitModule3((char *) "ndnSIM.ndn.nfd.cs", ndnSIM_ndn_nfd_cs_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdCsEntry_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdCsEntry_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::cs::Entry' class */
    if (PyType_Ready(&PyNs3NdnNfdCsEntry_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Entry", (PyObject *) &PyNs3NdnNfdCsEntry_Type);
    return m;
}
static PyMethodDef ndnSIM_ndn_nfd_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


std::map<void*, PyObject*> PyNs3NdnNfdForwarder_wrapper_registry;

static int
_wrap_PyNs3NdnNfdForwarder__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'Forwarder' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnNfdForwarder_getFib(PyNs3NdnNfdForwarder *self)
{
    PyObject *py_retval;
    PyNs3NdnNfdFib *py_Fib;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    ns3::ndn::nfd::Fib const & retval = self->obj->getFib();
    wrapper_lookup_iter = PyNs3NdnNfdFib_wrapper_registry.find((void *) (&retval));
    if (wrapper_lookup_iter == PyNs3NdnNfdFib_wrapper_registry.end()) {
        py_Fib = NULL;
    } else {
        py_Fib = (PyNs3NdnNfdFib *) wrapper_lookup_iter->second;
        Py_INCREF(py_Fib);
    }
    
    if (py_Fib == NULL) {
        py_Fib = PyObject_New(PyNs3NdnNfdFib, &PyNs3NdnNfdFib_Type);
        py_Fib->obj = (ns3::ndn::nfd::Fib *) ((&retval));
        py_Fib->flags = PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED;
        PyNs3NdnNfdFib_wrapper_registry[(void *) py_Fib->obj] = (PyObject *) py_Fib;
    }
    py_retval = Py_BuildValue((char *) "N", py_Fib);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNfdForwarder_getCs(PyNs3NdnNfdForwarder *self)
{
    PyObject *py_retval;
    PyNs3NdnNfdCs *py_Cs;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    ns3::ndn::nfd::Cs const & retval = self->obj->getCs();
    wrapper_lookup_iter = PyNs3NdnNfdCs_wrapper_registry.find((void *) (&retval));
    if (wrapper_lookup_iter == PyNs3NdnNfdCs_wrapper_registry.end()) {
        py_Cs = NULL;
    } else {
        py_Cs = (PyNs3NdnNfdCs *) wrapper_lookup_iter->second;
        Py_INCREF(py_Cs);
    }
    
    if (py_Cs == NULL) {
        py_Cs = PyObject_New(PyNs3NdnNfdCs, &PyNs3NdnNfdCs_Type);
        py_Cs->obj = (ns3::ndn::nfd::Cs *) ((&retval));
        py_Cs->flags = PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED;
        PyNs3NdnNfdCs_wrapper_registry[(void *) py_Cs->obj] = (PyObject *) py_Cs;
    }
    py_retval = Py_BuildValue((char *) "N", py_Cs);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNfdForwarder_getPit(PyNs3NdnNfdForwarder *self)
{
    PyObject *py_retval;
    PyNs3NdnNfdPit *py_Pit;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    ns3::ndn::nfd::Pit const & retval = self->obj->getPit();
    wrapper_lookup_iter = PyNs3NdnNfdPit_wrapper_registry.find((void *) (&retval));
    if (wrapper_lookup_iter == PyNs3NdnNfdPit_wrapper_registry.end()) {
        py_Pit = NULL;
    } else {
        py_Pit = (PyNs3NdnNfdPit *) wrapper_lookup_iter->second;
        Py_INCREF(py_Pit);
    }
    
    if (py_Pit == NULL) {
        py_Pit = PyObject_New(PyNs3NdnNfdPit, &PyNs3NdnNfdPit_Type);
        py_Pit->obj = (ns3::ndn::nfd::Pit *) ((&retval));
        py_Pit->flags = PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED;
        PyNs3NdnNfdPit_wrapper_registry[(void *) py_Pit->obj] = (PyObject *) py_Pit;
    }
    py_retval = Py_BuildValue((char *) "N", py_Pit);
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdForwarder_methods[] = {
    {(char *) "getFib", (PyCFunction) _wrap_PyNs3NdnNfdForwarder_getFib, METH_NOARGS, NULL },
    {(char *) "getCs", (PyCFunction) _wrap_PyNs3NdnNfdForwarder_getCs, METH_NOARGS, NULL },
    {(char *) "getPit", (PyCFunction) _wrap_PyNs3NdnNfdForwarder_getPit, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdForwarder__tp_dealloc(PyNs3NdnNfdForwarder *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdForwarder_wrapper_registry.find((void *) self->obj.get());
    if (wrapper_lookup_iter != PyNs3NdnNfdForwarder_wrapper_registry.end()) {
        PyNs3NdnNfdForwarder_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdForwarder__tp_richcompare (PyNs3NdnNfdForwarder *PYBINDGEN_UNUSED(self), PyNs3NdnNfdForwarder *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdForwarder_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnNfdForwarder_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.Forwarder",            /* tp_name */
    sizeof(PyNs3NdnNfdForwarder),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdForwarder__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdForwarder__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdForwarder_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdForwarder__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnNfdFib_wrapper_registry;

static int
_wrap_PyNs3NdnNfdFib__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'Fib' cannot be constructed ()");
    return -1;
}



PyObject *
_wrap_PyNs3NdnNfdFib_erase__0(PyNs3NdnNfdFib *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NdnName *prefix;
    const char *keywords[] = {"prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NdnName_Type, &prefix)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->erase(*((PyNs3NdnName *) prefix)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnNfdFib_erase__1(PyNs3NdnNfdFib *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NdnNfdFibEntry *entry;
    const char *keywords[] = {"entry", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NdnNfdFibEntry_Type, &entry)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->erase(*((PyNs3NdnNfdFibEntry *) entry)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3NdnNfdFib_erase(PyNs3NdnNfdFib *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3NdnNfdFib_erase__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnNfdFib_erase__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3NdnNfdFib_removeNextHopFromAllEntries(PyNs3NdnNfdFib *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NdnFace *face;
    ::std::shared_ptr< ns3::ndn::Face > face_ptr;
    const char *keywords[] = {"face", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NdnFace_Type, &face)) {
        return NULL;
    }
    if (face) { face_ptr = face->obj; }
    self->obj->removeNextHopFromAllEntries(face_ptr);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnNfdFib_size(PyNs3NdnNfdFib *self)
{
    PyObject *py_retval;
    size_t retval;
    
    retval = self->obj->size();
    py_retval = Py_BuildValue((char *) "K", ((unsigned PY_LONG_LONG) retval));
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdFib_methods[] = {
    {(char *) "erase", (PyCFunction) _wrap_PyNs3NdnNfdFib_erase, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "removeNextHopFromAllEntries", (PyCFunction) _wrap_PyNs3NdnNfdFib_removeNextHopFromAllEntries, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "size", (PyCFunction) _wrap_PyNs3NdnNfdFib_size, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdFib__tp_dealloc(PyNs3NdnNfdFib *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdFib_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNfdFib_wrapper_registry.end()) {
        PyNs3NdnNfdFib_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::nfd::Fib *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdFib__tp_richcompare (PyNs3NdnNfdFib *PYBINDGEN_UNUSED(self), PyNs3NdnNfdFib *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdFib_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}


static void
PyNs3NdnNfdFib_Iter__tp_clear(PyNs3NdnNfdFib_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
PyNs3NdnNfdFib_Iter__tp_traverse(PyNs3NdnNfdFib_Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_PyNs3NdnNfdFib_Iter__tp_dealloc(PyNs3NdnNfdFib_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_PyNs3NdnNfdFib__tp_iter(PyNs3NdnNfdFib *self)
{
    PyNs3NdnNfdFib_Iter *iter = PyObject_GC_New(PyNs3NdnNfdFib_Iter, &PyNs3NdnNfdFib_IterType);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new ns3::ndn::nfd::Fib::const_iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_PyNs3NdnNfdFib_Iter__tp_iter(PyNs3NdnNfdFib_Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_PyNs3NdnNfdFib_Iter__tp_iternext(PyNs3NdnNfdFib_Iter *self)
{
    PyObject *py_retval;
    ns3::ndn::nfd::Fib::const_iterator iter;
    PyNs3NdnNfdFibEntry *py_Entry;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    wrapper_lookup_iter = PyNs3NdnNfdFibEntry_wrapper_registry.find((void *) (&(*iter)));
    if (wrapper_lookup_iter == PyNs3NdnNfdFibEntry_wrapper_registry.end()) {
        py_Entry = NULL;
    } else {
        py_Entry = (PyNs3NdnNfdFibEntry *) wrapper_lookup_iter->second;
        Py_INCREF(py_Entry);
    }
    
    if (py_Entry == NULL) {
        py_Entry = PyObject_New(PyNs3NdnNfdFibEntry, &PyNs3NdnNfdFibEntry_Type);
        py_Entry->obj = (ns3::ndn::nfd::fib::Entry *) ((&(*iter)));
        py_Entry->flags = PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED;
        PyNs3NdnNfdFibEntry_wrapper_registry[(void *) py_Entry->obj] = (PyObject *) py_Entry;
    }
    py_retval = Py_BuildValue((char *) "N", py_Entry);
    return py_retval;
}
PyTypeObject PyNs3NdnNfdFib_IterType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.FibIter",            /* tp_name */
    sizeof(PyNs3NdnNfdFib_Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdFib_Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3NdnNfdFib_Iter__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3NdnNfdFib_Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnNfdFib_Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_PyNs3NdnNfdFib_Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject PyNs3NdnNfdFib_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.Fib",            /* tp_name */
    sizeof(PyNs3NdnNfdFib),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdFib__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdFib__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnNfdFib__tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdFib_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdFib__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnNfdPit_wrapper_registry;

static int
_wrap_PyNs3NdnNfdPit__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'Pit' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnNfdPit_size(PyNs3NdnNfdPit *self)
{
    PyObject *py_retval;
    size_t retval;
    
    retval = self->obj->size();
    py_retval = Py_BuildValue((char *) "K", ((unsigned PY_LONG_LONG) retval));
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdPit_methods[] = {
    {(char *) "size", (PyCFunction) _wrap_PyNs3NdnNfdPit_size, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdPit__tp_dealloc(PyNs3NdnNfdPit *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdPit_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNfdPit_wrapper_registry.end()) {
        PyNs3NdnNfdPit_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::nfd::Pit *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdPit__tp_richcompare (PyNs3NdnNfdPit *PYBINDGEN_UNUSED(self), PyNs3NdnNfdPit *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdPit_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}


static void
PyNs3NdnNfdPit_Iter__tp_clear(PyNs3NdnNfdPit_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
PyNs3NdnNfdPit_Iter__tp_traverse(PyNs3NdnNfdPit_Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_PyNs3NdnNfdPit_Iter__tp_dealloc(PyNs3NdnNfdPit_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_PyNs3NdnNfdPit__tp_iter(PyNs3NdnNfdPit *self)
{
    PyNs3NdnNfdPit_Iter *iter = PyObject_GC_New(PyNs3NdnNfdPit_Iter, &PyNs3NdnNfdPit_IterType);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new ns3::ndn::nfd::Pit::const_iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_PyNs3NdnNfdPit_Iter__tp_iter(PyNs3NdnNfdPit_Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_PyNs3NdnNfdPit_Iter__tp_iternext(PyNs3NdnNfdPit_Iter *self)
{
    PyObject *py_retval;
    ns3::ndn::nfd::Pit::const_iterator iter;
    PyNs3NdnNfdPitEntry *py_Entry;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    wrapper_lookup_iter = PyNs3NdnNfdPitEntry_wrapper_registry.find((void *) (&(*iter)));
    if (wrapper_lookup_iter == PyNs3NdnNfdPitEntry_wrapper_registry.end()) {
        py_Entry = NULL;
    } else {
        py_Entry = (PyNs3NdnNfdPitEntry *) wrapper_lookup_iter->second;
        Py_INCREF(py_Entry);
    }
    
    if (py_Entry == NULL) {
        py_Entry = PyObject_New(PyNs3NdnNfdPitEntry, &PyNs3NdnNfdPitEntry_Type);
        py_Entry->obj = (ns3::ndn::nfd::pit::Entry *) ((&(*iter)));
        py_Entry->flags = PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED;
        PyNs3NdnNfdPitEntry_wrapper_registry[(void *) py_Entry->obj] = (PyObject *) py_Entry;
    }
    py_retval = Py_BuildValue((char *) "N", py_Entry);
    return py_retval;
}
PyTypeObject PyNs3NdnNfdPit_IterType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.PitIter",            /* tp_name */
    sizeof(PyNs3NdnNfdPit_Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdPit_Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3NdnNfdPit_Iter__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3NdnNfdPit_Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnNfdPit_Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_PyNs3NdnNfdPit_Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject PyNs3NdnNfdPit_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.Pit",            /* tp_name */
    sizeof(PyNs3NdnNfdPit),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdPit__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdPit__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnNfdPit__tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdPit_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdPit__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnNfdCs_wrapper_registry;

static int
_wrap_PyNs3NdnNfdCs__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'Cs' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnNfdCs_size(PyNs3NdnNfdCs *self)
{
    PyObject *py_retval;
    size_t retval;
    
    retval = self->obj->size();
    py_retval = Py_BuildValue((char *) "K", ((unsigned PY_LONG_LONG) retval));
    return py_retval;
}

static PyMethodDef PyNs3NdnNfdCs_methods[] = {
    {(char *) "size", (PyCFunction) _wrap_PyNs3NdnNfdCs_size, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnNfdCs__tp_dealloc(PyNs3NdnNfdCs *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnNfdCs_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnNfdCs_wrapper_registry.end()) {
        PyNs3NdnNfdCs_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::nfd::Cs *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnNfdCs__tp_richcompare (PyNs3NdnNfdCs *PYBINDGEN_UNUSED(self), PyNs3NdnNfdCs *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnNfdCs_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}


static void
PyNs3NdnNfdCs_Iter__tp_clear(PyNs3NdnNfdCs_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
PyNs3NdnNfdCs_Iter__tp_traverse(PyNs3NdnNfdCs_Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_PyNs3NdnNfdCs_Iter__tp_dealloc(PyNs3NdnNfdCs_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_PyNs3NdnNfdCs__tp_iter(PyNs3NdnNfdCs *self)
{
    PyNs3NdnNfdCs_Iter *iter = PyObject_GC_New(PyNs3NdnNfdCs_Iter, &PyNs3NdnNfdCs_IterType);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new ns3::ndn::nfd::Cs::const_iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_PyNs3NdnNfdCs_Iter__tp_iter(PyNs3NdnNfdCs_Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_PyNs3NdnNfdCs_Iter__tp_iternext(PyNs3NdnNfdCs_Iter *self)
{
    PyObject *py_retval;
    ns3::ndn::nfd::Cs::const_iterator iter;
    PyNs3NdnNfdCsEntry *py_Entry;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    wrapper_lookup_iter = PyNs3NdnNfdCsEntry_wrapper_registry.find((void *) (&(*iter)));
    if (wrapper_lookup_iter == PyNs3NdnNfdCsEntry_wrapper_registry.end()) {
        py_Entry = NULL;
    } else {
        py_Entry = (PyNs3NdnNfdCsEntry *) wrapper_lookup_iter->second;
        Py_INCREF(py_Entry);
    }
    
    if (py_Entry == NULL) {
        py_Entry = PyObject_New(PyNs3NdnNfdCsEntry, &PyNs3NdnNfdCsEntry_Type);
        py_Entry->obj = (ns3::ndn::nfd::cs::Entry *) ((&(*iter)));
        py_Entry->flags = PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED;
        PyNs3NdnNfdCsEntry_wrapper_registry[(void *) py_Entry->obj] = (PyObject *) py_Entry;
    }
    py_retval = Py_BuildValue((char *) "N", py_Entry);
    return py_retval;
}
PyTypeObject PyNs3NdnNfdCs_IterType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.CsIter",            /* tp_name */
    sizeof(PyNs3NdnNfdCs_Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdCs_Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3NdnNfdCs_Iter__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3NdnNfdCs_Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnNfdCs_Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_PyNs3NdnNfdCs_Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject PyNs3NdnNfdCs_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.nfd.Cs",            /* tp_name */
    sizeof(PyNs3NdnNfdCs),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnNfdCs__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnNfdCs__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnNfdCs__tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnNfdCs_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnNfdCs__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef ndnSIM_ndn_nfd_moduledef = {
    PyModuleDef_HEAD_INIT,
    "ndnSIM.ndn.nfd",
    NULL,
    -1,
    ndnSIM_ndn_nfd_functions,
};
#endif

static PyObject *
initndnSIM_ndn_nfd(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&ndnSIM_ndn_nfd_moduledef);
    #else
    m = Py_InitModule3((char *) "ndnSIM.ndn.nfd", ndnSIM_ndn_nfd_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdForwarder_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdForwarder_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::Forwarder' class */
    if (PyType_Ready(&PyNs3NdnNfdForwarder_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Forwarder", (PyObject *) &PyNs3NdnNfdForwarder_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdFib_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdFib_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::Fib' class */
    if (PyType_Ready(&PyNs3NdnNfdFib_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Fib", (PyObject *) &PyNs3NdnNfdFib_Type);
    /* Register the 'ns3::ndn::nfd::Fib' class iterator*/
    if (PyType_Ready(&PyNs3NdnNfdFib_IterType)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "FibIter", (PyObject *) &PyNs3NdnNfdFib_IterType);
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdPit_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdPit_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::Pit' class */
    if (PyType_Ready(&PyNs3NdnNfdPit_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Pit", (PyObject *) &PyNs3NdnNfdPit_Type);
    /* Register the 'ns3::ndn::nfd::Pit' class iterator*/
    if (PyType_Ready(&PyNs3NdnNfdPit_IterType)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "PitIter", (PyObject *) &PyNs3NdnNfdPit_IterType);
    PyModule_AddObject(m, (char *) "_PyNs3NdnNfdCs_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnNfdCs_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::nfd::Cs' class */
    if (PyType_Ready(&PyNs3NdnNfdCs_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Cs", (PyObject *) &PyNs3NdnNfdCs_Type);
    /* Register the 'ns3::ndn::nfd::Cs' class iterator*/
    if (PyType_Ready(&PyNs3NdnNfdCs_IterType)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "CsIter", (PyObject *) &PyNs3NdnNfdCs_IterType);
    submodule = initndnSIM_ndn_nfd_fib();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "fib", submodule);
    submodule = initndnSIM_ndn_nfd_pit();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "pit", submodule);
    submodule = initndnSIM_ndn_nfd_cs();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "cs", submodule);
    return m;
}
static PyMethodDef ndnSIM_ndn_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


std::map<void*, PyObject*> PyNs3NdnStackHelper_wrapper_registry;

static int
_wrap_PyNs3NdnStackHelper__tp_init(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::ndn::StackHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3NdnStackHelper_SetOldContentStore(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *contentStoreClass;
    Py_ssize_t contentStoreClass_len;
    std::string contentStoreClass_std;
    const char *attr1;
    Py_ssize_t attr1_len;
    std::string attr1_std;
    const char *value1;
    Py_ssize_t value1_len;
    std::string value1_std;
    const char *attr2;
    Py_ssize_t attr2_len;
    std::string attr2_std;
    const char *value2;
    Py_ssize_t value2_len;
    std::string value2_std;
    const char *attr3;
    Py_ssize_t attr3_len;
    std::string attr3_std;
    const char *value3;
    Py_ssize_t value3_len;
    std::string value3_std;
    const char *attr4;
    Py_ssize_t attr4_len;
    std::string attr4_std;
    const char *value4;
    Py_ssize_t value4_len;
    std::string value4_std;
    const char *keywords[] = {"contentStoreClass", "attr1", "value1", "attr2", "value2", "attr3", "value3", "attr4", "value4", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#s#s#s#s#s#s#", (char **) keywords, &contentStoreClass, &contentStoreClass_len, &attr1, &attr1_len, &value1, &value1_len, &attr2, &attr2_len, &value2, &value2_len, &attr3, &attr3_len, &value3, &value3_len, &attr4, &attr4_len, &value4, &value4_len)) {
        return NULL;
    }
    contentStoreClass_std = std::string(contentStoreClass, contentStoreClass_len);
    attr1_std = std::string(attr1, attr1_len);
    value1_std = std::string(value1, value1_len);
    attr2_std = std::string(attr2, attr2_len);
    value2_std = std::string(value2, value2_len);
    attr3_std = std::string(attr3, attr3_len);
    value3_std = std::string(value3, value3_len);
    attr4_std = std::string(attr4, attr4_len);
    value4_std = std::string(value4, value4_len);
    self->obj->SetOldContentStore(contentStoreClass_std, attr1_std, value1_std, attr2_std, value2_std, attr3_std, value3_std, attr4_std, value4_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnStackHelper_InstallAll(PyNs3NdnStackHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::ndn::FaceContainer > retval;
    PyNs3NdnFaceContainer *py_FaceContainer;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    retval = self->obj->InstallAll();
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3NdnFaceContainer_wrapper_registry.find((void *) ::ns3::PeekPointer(retval));
    if (wrapper_lookup_iter == PyNs3NdnFaceContainer_wrapper_registry.end()) {
        py_FaceContainer = NULL;
    } else {
        py_FaceContainer = (PyNs3NdnFaceContainer *) wrapper_lookup_iter->second;
        Py_INCREF(py_FaceContainer);
    }
    
    if (py_FaceContainer == NULL) {
        py_FaceContainer = PyObject_New(PyNs3NdnFaceContainer, &PyNs3NdnFaceContainer_Type);
        new(&py_FaceContainer->obj) ns3::Ptr< ns3::ndn::FaceContainer >;
        py_FaceContainer->obj = retval;
        py_FaceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3NdnFaceContainer_wrapper_registry[(void *) ::ns3::PeekPointer(py_FaceContainer->obj)] = (PyObject *) py_FaceContainer;
    } else {
        retval->Unref();
    }
    py_retval = Py_BuildValue((char *) "N", py_FaceContainer);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnStackHelper_SetStackAttributes(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *attr1;
    Py_ssize_t attr1_len;
    std::string attr1_std;
    const char *value1;
    Py_ssize_t value1_len;
    std::string value1_std;
    const char *attr2;
    Py_ssize_t attr2_len;
    std::string attr2_std;
    const char *value2;
    Py_ssize_t value2_len;
    std::string value2_std;
    const char *attr3;
    Py_ssize_t attr3_len;
    std::string attr3_std;
    const char *value3;
    Py_ssize_t value3_len;
    std::string value3_std;
    const char *attr4;
    Py_ssize_t attr4_len;
    std::string attr4_std;
    const char *value4;
    Py_ssize_t value4_len;
    std::string value4_std;
    const char *keywords[] = {"attr1", "value1", "attr2", "value2", "attr3", "value3", "attr4", "value4", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#s#s#s#s#s#", (char **) keywords, &attr1, &attr1_len, &value1, &value1_len, &attr2, &attr2_len, &value2, &value2_len, &attr3, &attr3_len, &value3, &value3_len, &attr4, &attr4_len, &value4, &value4_len)) {
        return NULL;
    }
    attr1_std = std::string(attr1, attr1_len);
    value1_std = std::string(value1, value1_len);
    attr2_std = std::string(attr2, attr2_len);
    value2_std = std::string(value2, value2_len);
    attr3_std = std::string(attr3, attr3_len);
    value3_std = std::string(value3, value3_len);
    attr4_std = std::string(attr4, attr4_len);
    value4_std = std::string(value4, value4_len);
    self->obj->SetStackAttributes(attr1_std, value1_std, attr2_std, value2_std, attr3_std, value3_std, attr4_std, value4_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnStackHelper_setCsSize(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned PY_LONG_LONG maxSize;
    const char *keywords[] = {"maxSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "K", (char **) keywords, &maxSize)) {
        return NULL;
    }
    self->obj->setCsSize(maxSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnStackHelper_SetDefaultRoutes(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool isEnabled;
    PyObject *py_isEnabled = NULL;
    const char *keywords[] = {"isEnabled", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &py_isEnabled)) {
        return NULL;
    }
    isEnabled = py_isEnabled? (bool) PyObject_IsTrue(py_isEnabled) : true;
    self->obj->SetDefaultRoutes(isEnabled);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3NdnStackHelper_Install__0(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::ndn::FaceContainer > retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3NdnFaceContainer *py_FaceContainer;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3NdnFaceContainer_wrapper_registry.find((void *) ::ns3::PeekPointer(retval));
    if (wrapper_lookup_iter == PyNs3NdnFaceContainer_wrapper_registry.end()) {
        py_FaceContainer = NULL;
    } else {
        py_FaceContainer = (PyNs3NdnFaceContainer *) wrapper_lookup_iter->second;
        Py_INCREF(py_FaceContainer);
    }
    
    if (py_FaceContainer == NULL) {
        py_FaceContainer = PyObject_New(PyNs3NdnFaceContainer, &PyNs3NdnFaceContainer_Type);
        new(&py_FaceContainer->obj) ns3::Ptr< ns3::ndn::FaceContainer >;
        py_FaceContainer->obj = retval;
        py_FaceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3NdnFaceContainer_wrapper_registry[(void *) ::ns3::PeekPointer(py_FaceContainer->obj)] = (PyObject *) py_FaceContainer;
    } else {
        retval->Unref();
    }
    py_retval = Py_BuildValue((char *) "N", py_FaceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnStackHelper_Install__1(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::ndn::FaceContainer > retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    std::string nodeName_std;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3NdnFaceContainer *py_FaceContainer;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    nodeName_std = std::string(nodeName, nodeName_len);
    retval = self->obj->Install(nodeName_std);
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3NdnFaceContainer_wrapper_registry.find((void *) ::ns3::PeekPointer(retval));
    if (wrapper_lookup_iter == PyNs3NdnFaceContainer_wrapper_registry.end()) {
        py_FaceContainer = NULL;
    } else {
        py_FaceContainer = (PyNs3NdnFaceContainer *) wrapper_lookup_iter->second;
        Py_INCREF(py_FaceContainer);
    }
    
    if (py_FaceContainer == NULL) {
        py_FaceContainer = PyObject_New(PyNs3NdnFaceContainer, &PyNs3NdnFaceContainer_Type);
        new(&py_FaceContainer->obj) ns3::Ptr< ns3::ndn::FaceContainer >;
        py_FaceContainer->obj = retval;
        py_FaceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3NdnFaceContainer_wrapper_registry[(void *) ::ns3::PeekPointer(py_FaceContainer->obj)] = (PyObject *) py_FaceContainer;
    } else {
        retval->Unref();
    }
    py_retval = Py_BuildValue((char *) "N", py_FaceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnStackHelper_Install__2(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::ndn::FaceContainer > retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3NdnFaceContainer *py_FaceContainer;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3NdnFaceContainer_wrapper_registry.find((void *) ::ns3::PeekPointer(retval));
    if (wrapper_lookup_iter == PyNs3NdnFaceContainer_wrapper_registry.end()) {
        py_FaceContainer = NULL;
    } else {
        py_FaceContainer = (PyNs3NdnFaceContainer *) wrapper_lookup_iter->second;
        Py_INCREF(py_FaceContainer);
    }
    
    if (py_FaceContainer == NULL) {
        py_FaceContainer = PyObject_New(PyNs3NdnFaceContainer, &PyNs3NdnFaceContainer_Type);
        new(&py_FaceContainer->obj) ns3::Ptr< ns3::ndn::FaceContainer >;
        py_FaceContainer->obj = retval;
        py_FaceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3NdnFaceContainer_wrapper_registry[(void *) ::ns3::PeekPointer(py_FaceContainer->obj)] = (PyObject *) py_FaceContainer;
    } else {
        retval->Unref();
    }
    py_retval = Py_BuildValue((char *) "N", py_FaceContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3NdnStackHelper_Install(PyNs3NdnStackHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3NdnStackHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnStackHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3NdnStackHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}

static PyMethodDef PyNs3NdnStackHelper_methods[] = {
    {(char *) "SetOldContentStore", (PyCFunction) _wrap_PyNs3NdnStackHelper_SetOldContentStore, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InstallAll", (PyCFunction) _wrap_PyNs3NdnStackHelper_InstallAll, METH_NOARGS, NULL },
    {(char *) "SetStackAttributes", (PyCFunction) _wrap_PyNs3NdnStackHelper_SetStackAttributes, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "setCsSize", (PyCFunction) _wrap_PyNs3NdnStackHelper_setCsSize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDefaultRoutes", (PyCFunction) _wrap_PyNs3NdnStackHelper_SetDefaultRoutes, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3NdnStackHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnStackHelper__tp_dealloc(PyNs3NdnStackHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnStackHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnStackHelper_wrapper_registry.end()) {
        PyNs3NdnStackHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::StackHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnStackHelper__tp_richcompare (PyNs3NdnStackHelper *PYBINDGEN_UNUSED(self), PyNs3NdnStackHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnStackHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnStackHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.StackHelper",            /* tp_name */
    sizeof(PyNs3NdnStackHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnStackHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnStackHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnStackHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnStackHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnFibHelper_wrapper_registry;

static int
_wrap_PyNs3NdnFibHelper__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'FibHelper' cannot be constructed ()");
    return -1;
}



PyObject *
_wrap_PyNs3NdnFibHelper_AddRoute__0(PyNs3NdnFibHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    std::string nodeName_std;
    const char *prefix;
    Py_ssize_t prefix_len;
    std::string prefix_std;
    unsigned int faceId;
    int32_t metric;
    const char *keywords[] = {"nodeName", "prefix", "faceId", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#Ii", (char **) keywords, &nodeName, &nodeName_len, &prefix, &prefix_len, &faceId, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    nodeName_std = std::string(nodeName, nodeName_len);
    prefix_std = std::string(prefix, prefix_len);
    ns3::ndn::FibHelper::AddRoute(nodeName_std, prefix_std, faceId, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnFibHelper_AddRoute__1(PyNs3NdnFibHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    PyNs3NdnName *prefix;
    unsigned int faceId;
    int32_t metric;
    const char *keywords[] = {"node", "prefix", "faceId", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!Ii", (char **) keywords, &PyNs3Node_Type, &node, &PyNs3NdnName_Type, &prefix, &faceId, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ndn::FibHelper::AddRoute(ns3::Ptr< ns3::Node  > (node_ptr), *((PyNs3NdnName *) prefix)->obj, faceId, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnFibHelper_AddRoute__2(PyNs3NdnFibHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    PyNs3NdnName *prefix;
    PyNs3NdnFace *face;
    ::std::shared_ptr< ns3::ndn::Face > face_ptr;
    int32_t metric;
    const char *keywords[] = {"node", "prefix", "face", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!i", (char **) keywords, &PyNs3Node_Type, &node, &PyNs3NdnName_Type, &prefix, &PyNs3NdnFace_Type, &face, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    if (face) { face_ptr = face->obj; }
    ns3::ndn::FibHelper::AddRoute(ns3::Ptr< ns3::Node  > (node_ptr), *((PyNs3NdnName *) prefix)->obj, face_ptr, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnFibHelper_AddRoute__3(PyNs3NdnFibHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    PyNs3NdnName *prefix;
    PyNs3Node *otherNode;
    ns3::Node *otherNode_ptr;
    int32_t metric;
    const char *keywords[] = {"node", "prefix", "otherNode", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!i", (char **) keywords, &PyNs3Node_Type, &node, &PyNs3NdnName_Type, &prefix, &PyNs3Node_Type, &otherNode, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    otherNode_ptr = (otherNode ? otherNode->obj : NULL);
    ns3::ndn::FibHelper::AddRoute(ns3::Ptr< ns3::Node  > (node_ptr), *((PyNs3NdnName *) prefix)->obj, ns3::Ptr< ns3::Node  > (otherNode_ptr), metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnFibHelper_AddRoute__4(PyNs3NdnFibHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    std::string nodeName_std;
    const char *prefix;
    Py_ssize_t prefix_len;
    std::string prefix_std;
    const char *otherNodeName;
    Py_ssize_t otherNodeName_len;
    std::string otherNodeName_std;
    int32_t metric;
    const char *keywords[] = {"nodeName", "prefix", "otherNodeName", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#i", (char **) keywords, &nodeName, &nodeName_len, &prefix, &prefix_len, &otherNodeName, &otherNodeName_len, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    nodeName_std = std::string(nodeName, nodeName_len);
    prefix_std = std::string(prefix, prefix_len);
    otherNodeName_std = std::string(otherNodeName, otherNodeName_len);
    ns3::ndn::FibHelper::AddRoute(nodeName_std, prefix_std, otherNodeName_std, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3NdnFibHelper_AddRoute(PyNs3NdnFibHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3NdnFibHelper_AddRoute__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnFibHelper_AddRoute__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3NdnFibHelper_AddRoute__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3NdnFibHelper_AddRoute__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3NdnFibHelper_AddRoute__4(self, args, kwargs, &exceptions[4]);
    if (!exceptions[4]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        return retval;
    }
    error_list = PyList_New(5);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyList_SET_ITEM(error_list, 3, PyObject_Str(exceptions[3]));
    Py_DECREF(exceptions[3]);
    PyList_SET_ITEM(error_list, 4, PyObject_Str(exceptions[4]));
    Py_DECREF(exceptions[4]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}

static PyMethodDef PyNs3NdnFibHelper_methods[] = {
    {(char *) "AddRoute", (PyCFunction) _wrap_PyNs3NdnFibHelper_AddRoute, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnFibHelper__tp_dealloc(PyNs3NdnFibHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnFibHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnFibHelper_wrapper_registry.end()) {
        PyNs3NdnFibHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::FibHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnFibHelper__tp_richcompare (PyNs3NdnFibHelper *PYBINDGEN_UNUSED(self), PyNs3NdnFibHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnFibHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnFibHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.FibHelper",            /* tp_name */
    sizeof(PyNs3NdnFibHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnFibHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnFibHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnFibHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnFibHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnStrategyChoiceHelper_wrapper_registry;

static int
_wrap_PyNs3NdnStrategyChoiceHelper__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'StrategyChoiceHelper' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnStrategyChoiceHelper_InstallAll(PyNs3NdnStrategyChoiceHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    std::string name_std;
    const char *strategy;
    Py_ssize_t strategy_len;
    std::string strategy_std;
    const char *keywords[] = {"name", "strategy", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &name, &name_len, &strategy, &strategy_len)) {
        return NULL;
    }
    name_std = std::string(name, name_len);
    strategy_std = std::string(strategy, strategy_len);
    ns3::ndn::StrategyChoiceHelper::InstallAll(name_std, strategy_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3NdnStrategyChoiceHelper_Install__0(PyNs3NdnStrategyChoiceHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *name;
    Py_ssize_t name_len;
    std::string name_std;
    const char *strategy;
    Py_ssize_t strategy_len;
    std::string strategy_std;
    const char *keywords[] = {"node", "name", "strategy", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#s#", (char **) keywords, &PyNs3Node_Type, &node, &name, &name_len, &strategy, &strategy_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    name_std = std::string(name, name_len);
    strategy_std = std::string(strategy, strategy_len);
    ns3::ndn::StrategyChoiceHelper::Install(ns3::Ptr< ns3::Node  > (node_ptr), name_std, strategy_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnStrategyChoiceHelper_Install__1(PyNs3NdnStrategyChoiceHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *name;
    Py_ssize_t name_len;
    std::string name_std;
    const char *strategy;
    Py_ssize_t strategy_len;
    std::string strategy_std;
    const char *keywords[] = {"c", "name", "strategy", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#s#", (char **) keywords, &PyNs3NodeContainer_Type, &c, &name, &name_len, &strategy, &strategy_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    name_std = std::string(name, name_len);
    strategy_std = std::string(strategy, strategy_len);
    ns3::ndn::StrategyChoiceHelper::Install(*((PyNs3NodeContainer *) c)->obj, name_std, strategy_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3NdnStrategyChoiceHelper_Install(PyNs3NdnStrategyChoiceHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3NdnStrategyChoiceHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnStrategyChoiceHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}

static PyMethodDef PyNs3NdnStrategyChoiceHelper_methods[] = {
    {(char *) "InstallAll", (PyCFunction) _wrap_PyNs3NdnStrategyChoiceHelper_InstallAll, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3NdnStrategyChoiceHelper_Install, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnStrategyChoiceHelper__tp_dealloc(PyNs3NdnStrategyChoiceHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnStrategyChoiceHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnStrategyChoiceHelper_wrapper_registry.end()) {
        PyNs3NdnStrategyChoiceHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::StrategyChoiceHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnStrategyChoiceHelper__tp_richcompare (PyNs3NdnStrategyChoiceHelper *PYBINDGEN_UNUSED(self), PyNs3NdnStrategyChoiceHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnStrategyChoiceHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnStrategyChoiceHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.StrategyChoiceHelper",            /* tp_name */
    sizeof(PyNs3NdnStrategyChoiceHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnStrategyChoiceHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnStrategyChoiceHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnStrategyChoiceHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnStrategyChoiceHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnAppHelper_wrapper_registry;

static int
_wrap_PyNs3NdnAppHelper__tp_init(PyNs3NdnAppHelper *self, PyObject *args, PyObject *kwargs)
{
    const char *prefix;
    Py_ssize_t prefix_len;
    std::string prefix_std;
    const char *keywords[] = {"prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &prefix, &prefix_len)) {
        return -1;
    }
    prefix_std = std::string(prefix, prefix_len);
    self->obj = new ns3::ndn::AppHelper(prefix_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3NdnAppHelper_SetAttribute(PyNs3NdnAppHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnAppHelper_SetPrefix(PyNs3NdnAppHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    std::string prefix_std;
    const char *keywords[] = {"prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &prefix, &prefix_len)) {
        return NULL;
    }
    prefix_std = std::string(prefix, prefix_len);
    self->obj->SetPrefix(prefix_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3NdnAppHelper_Install__0(PyNs3NdnAppHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnAppHelper_Install__1(PyNs3NdnAppHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ApplicationContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnAppHelper_Install__2(PyNs3NdnAppHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(std::string(nodeName, nodeName_len));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3NdnAppHelper_Install(PyNs3NdnAppHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3NdnAppHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnAppHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3NdnAppHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}

static PyMethodDef PyNs3NdnAppHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3NdnAppHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPrefix", (PyCFunction) _wrap_PyNs3NdnAppHelper_SetPrefix, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3NdnAppHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnAppHelper__tp_dealloc(PyNs3NdnAppHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnAppHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnAppHelper_wrapper_registry.end()) {
        PyNs3NdnAppHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::AppHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnAppHelper__tp_richcompare (PyNs3NdnAppHelper *PYBINDGEN_UNUSED(self), PyNs3NdnAppHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnAppHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnAppHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.AppHelper",            /* tp_name */
    sizeof(PyNs3NdnAppHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnAppHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnAppHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnAppHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnAppHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnGlobalRoutingHelper_wrapper_registry;

static int
_wrap_PyNs3NdnGlobalRoutingHelper__tp_init(PyNs3NdnGlobalRoutingHelper *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::ndn::GlobalRoutingHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_AddOriginsForAll(PyNs3NdnGlobalRoutingHelper *self)
{
    PyObject *py_retval;
    
    self->obj->AddOriginsForAll();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_AddOrigin__0(PyNs3NdnGlobalRoutingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    std::string prefix_std;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"prefix", "node", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &prefix, &prefix_len, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    prefix_std = std::string(prefix, prefix_len);
    node_ptr = (node ? node->obj : NULL);
    self->obj->AddOrigin(prefix_std, ns3::Ptr< ns3::Node  > (node_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_AddOrigin__1(PyNs3NdnGlobalRoutingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    std::string prefix_std;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    std::string nodeName_std;
    const char *keywords[] = {"prefix", "nodeName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &prefix, &prefix_len, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    prefix_std = std::string(prefix, prefix_len);
    nodeName_std = std::string(nodeName, nodeName_len);
    self->obj->AddOrigin(prefix_std, nodeName_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3NdnGlobalRoutingHelper_AddOrigin(PyNs3NdnGlobalRoutingHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3NdnGlobalRoutingHelper_AddOrigin__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnGlobalRoutingHelper_AddOrigin__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_InstallAll(PyNs3NdnGlobalRoutingHelper *self)
{
    PyObject *py_retval;
    
    self->obj->InstallAll();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_CalculateAllPossibleRoutes(PyNs3NdnGlobalRoutingHelper *self)
{
    PyObject *py_retval;
    
    self->obj->CalculateAllPossibleRoutes();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_AddOrigins(PyNs3NdnGlobalRoutingHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    std::string prefix_std;
    PyNs3NodeContainer *nodes;
    const char *keywords[] = {"prefix", "nodes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &prefix, &prefix_len, &PyNs3NodeContainer_Type, &nodes)) {
        return NULL;
    }
    prefix_std = std::string(prefix, prefix_len);
    self->obj->AddOrigins(prefix_std, *((PyNs3NodeContainer *) nodes)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_CalculateRoutes(PyNs3NdnGlobalRoutingHelper *self)
{
    PyObject *py_retval;
    
    self->obj->CalculateRoutes();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_Install__0(PyNs3NdnGlobalRoutingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3NdnGlobalRoutingHelper_Install__1(PyNs3NdnGlobalRoutingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *nodes;
    const char *keywords[] = {"nodes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &nodes)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Install(*((PyNs3NodeContainer *) nodes)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3NdnGlobalRoutingHelper_Install(PyNs3NdnGlobalRoutingHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3NdnGlobalRoutingHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnGlobalRoutingHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}

static PyMethodDef PyNs3NdnGlobalRoutingHelper_methods[] = {
    {(char *) "AddOriginsForAll", (PyCFunction) _wrap_PyNs3NdnGlobalRoutingHelper_AddOriginsForAll, METH_NOARGS, NULL },
    {(char *) "AddOrigin", (PyCFunction) _wrap_PyNs3NdnGlobalRoutingHelper_AddOrigin, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InstallAll", (PyCFunction) _wrap_PyNs3NdnGlobalRoutingHelper_InstallAll, METH_NOARGS, NULL },
    {(char *) "CalculateAllPossibleRoutes", (PyCFunction) _wrap_PyNs3NdnGlobalRoutingHelper_CalculateAllPossibleRoutes, METH_NOARGS, NULL },
    {(char *) "AddOrigins", (PyCFunction) _wrap_PyNs3NdnGlobalRoutingHelper_AddOrigins, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "CalculateRoutes", (PyCFunction) _wrap_PyNs3NdnGlobalRoutingHelper_CalculateRoutes, METH_NOARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3NdnGlobalRoutingHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnGlobalRoutingHelper__tp_dealloc(PyNs3NdnGlobalRoutingHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnGlobalRoutingHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnGlobalRoutingHelper_wrapper_registry.end()) {
        PyNs3NdnGlobalRoutingHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::GlobalRoutingHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnGlobalRoutingHelper__tp_richcompare (PyNs3NdnGlobalRoutingHelper *PYBINDGEN_UNUSED(self), PyNs3NdnGlobalRoutingHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnGlobalRoutingHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnGlobalRoutingHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.GlobalRoutingHelper",            /* tp_name */
    sizeof(PyNs3NdnGlobalRoutingHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnGlobalRoutingHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnGlobalRoutingHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnGlobalRoutingHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnGlobalRoutingHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static int
_wrap_PyNs3NdnL3Protocol__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'L3Protocol' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnL3Protocol_getForwarder(PyNs3NdnL3Protocol *self)
{
    PyObject *py_retval;
    std::shared_ptr< ns3::ndn::nfd::Forwarder > retval;
    PyNs3NdnNfdForwarder *py_Forwarder;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    retval = self->obj->getForwarder();
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3NdnNfdForwarder_wrapper_registry.find((void *) retval.get());
    if (wrapper_lookup_iter == PyNs3NdnNfdForwarder_wrapper_registry.end()) {
        py_Forwarder = NULL;
    } else {
        py_Forwarder = (PyNs3NdnNfdForwarder *) wrapper_lookup_iter->second;
        Py_INCREF(py_Forwarder);
    }
    
    if (py_Forwarder == NULL) {
        py_Forwarder = PyObject_New(PyNs3NdnNfdForwarder, &PyNs3NdnNfdForwarder_Type);
        new(&py_Forwarder->obj) ::std::shared_ptr< ns3::ndn::nfd::Forwarder >;
        py_Forwarder->obj = retval;
        py_Forwarder->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3NdnNfdForwarder_wrapper_registry[(void *) py_Forwarder->obj.get()] = (PyObject *) py_Forwarder;
    }
    py_retval = Py_BuildValue((char *) "N", py_Forwarder);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnL3Protocol_getL3Protocol(PyNs3NdnL3Protocol *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::ndn::L3Protocol > retval;
    PyNs3Object *node;
    ns3::Object *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3NdnL3Protocol *py_L3Protocol;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Object_Type, &node)) {
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    retval = ns3::ndn::L3Protocol::getL3Protocol(ns3::Ptr< ns3::Object  > (node_ptr));
    if (!(const_cast<ns3::ndn::L3Protocol *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::ndn::L3Protocol *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_L3Protocol = NULL;
    } else {
        py_L3Protocol = (PyNs3NdnL3Protocol *) wrapper_lookup_iter->second;
        Py_INCREF(py_L3Protocol);
    }
    
    if (py_L3Protocol == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::ndn::L3Protocol *> (ns3::PeekPointer (retval)))), &PyNs3NdnL3Protocol_Type);
        py_L3Protocol = PyObject_GC_New(PyNs3NdnL3Protocol, wrapper_type);
        py_L3Protocol->inst_dict = NULL;
    
        py_L3Protocol->inst_dict = NULL;
        py_L3Protocol->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::ndn::L3Protocol *> (ns3::PeekPointer (retval))->Ref();
        py_L3Protocol->obj = const_cast<ns3::ndn::L3Protocol *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_L3Protocol->obj] = (PyObject *) py_L3Protocol;
    }
    py_retval = Py_BuildValue((char *) "N", py_L3Protocol);
    return py_retval;
}

static PyMethodDef PyNs3NdnL3Protocol_methods[] = {
    {(char *) "getForwarder", (PyCFunction) _wrap_PyNs3NdnL3Protocol_getForwarder, METH_NOARGS, NULL },
    {(char *) "getL3Protocol", (PyCFunction) _wrap_PyNs3NdnL3Protocol_getL3Protocol, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3NdnL3Protocol__tp_clear(PyNs3NdnL3Protocol *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ndn::L3Protocol *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3NdnL3Protocol__tp_traverse(PyNs3NdnL3Protocol *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3NdnL3Protocol__tp_dealloc(PyNs3NdnL3Protocol *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3NdnL3Protocol__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnL3Protocol__tp_richcompare (PyNs3NdnL3Protocol *PYBINDGEN_UNUSED(self), PyNs3NdnL3Protocol *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnL3Protocol_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnL3Protocol_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.L3Protocol",            /* tp_name */
    sizeof(PyNs3NdnL3Protocol),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnL3Protocol__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3NdnL3Protocol__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3NdnL3Protocol__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnL3Protocol__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnL3Protocol_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3NdnL3Protocol, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnL3Protocol__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnName_wrapper_registry;


static int
_wrap_PyNs3NdnName__tp_init__0(PyNs3NdnName *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ndn::Name();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3NdnName__tp_init__1(PyNs3NdnName *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3NdnName *other;
    const char *keywords[] = {"other", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NdnName_Type, &other)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ndn::Name(*((PyNs3NdnName *) other)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3NdnName__tp_init__2(PyNs3NdnName *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *url;
    Py_ssize_t url_len;
    std::string url_std;
    const char *keywords[] = {"url", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &url, &url_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    url_std = std::string(url, url_len);
    self->obj = new ns3::ndn::Name(url_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3NdnName__tp_init(PyNs3NdnName *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3NdnName__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnName__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3NdnName__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3NdnName_getPrefix(PyNs3NdnName *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned PY_LONG_LONG len;
    const char *keywords[] = {"len", NULL};
    PyNs3NdnName *py_Name;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "K", (char **) keywords, &len)) {
        return NULL;
    }
    ns3::ndn::Name retval = self->obj->getPrefix(len);
    py_Name = PyObject_New(PyNs3NdnName, &PyNs3NdnName_Type);
    py_Name->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Name->obj = new ns3::ndn::Name(retval);
    PyNs3NdnName_wrapper_registry[(void *) py_Name->obj] = (PyObject *) py_Name;
    py_retval = Py_BuildValue((char *) "N", py_Name);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnName_size(PyNs3NdnName *self)
{
    PyObject *py_retval;
    size_t retval;
    
    retval = self->obj->size();
    py_retval = Py_BuildValue((char *) "K", ((unsigned PY_LONG_LONG) retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnName_toUri(PyNs3NdnName *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->toUri();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnName_append(PyNs3NdnName *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NdnNameComponent *comp;
    const char *keywords[] = {"comp", NULL};
    PyNs3NdnName *py_Name;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NdnNameComponent_Type, &comp)) {
        return NULL;
    }
    ns3::ndn::Name & retval = self->obj->append(*((PyNs3NdnNameComponent *) comp)->obj);
    py_Name = PyObject_New(PyNs3NdnName, &PyNs3NdnName_Type);
    py_Name->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Name->obj = new ns3::ndn::Name(retval);
    PyNs3NdnName_wrapper_registry[(void *) py_Name->obj] = (PyObject *) py_Name;
    py_retval = Py_BuildValue((char *) "N", py_Name);
    return py_retval;
}


PyObject *
_wrap_PyNs3NdnName_get(PyNs3NdnName *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int index;
    const char *keywords[] = {"index", NULL};
    PyNs3NdnNameComponent *py_Component;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &index)) {
        return NULL;
    }
    ns3::ndn::name::Component const & retval = self->obj->get(index);
    py_Component = PyObject_New(PyNs3NdnNameComponent, &PyNs3NdnNameComponent_Type);
    py_Component->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Component->obj = new ns3::ndn::name::Component(retval);
    PyNs3NdnNameComponent_wrapper_registry[(void *) py_Component->obj] = (PyObject *) py_Component;
    py_retval = Py_BuildValue((char *) "N", py_Component);
    return py_retval;
}


static PyObject*
_wrap_PyNs3NdnName__copy__(PyNs3NdnName *self)
{

    PyNs3NdnName *py_copy;
    py_copy = PyObject_New(PyNs3NdnName, &PyNs3NdnName_Type);
    py_copy->obj = new ns3::ndn::Name(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3NdnName_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3NdnName_methods[] = {
    {(char *) "getPrefix", (PyCFunction) _wrap_PyNs3NdnName_getPrefix, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "size", (PyCFunction) _wrap_PyNs3NdnName_size, METH_NOARGS, NULL },
    {(char *) "toUri", (PyCFunction) _wrap_PyNs3NdnName_toUri, METH_NOARGS, NULL },
    {(char *) "append", (PyCFunction) _wrap_PyNs3NdnName_append, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "get", (PyCFunction) _wrap_PyNs3NdnName_get, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3NdnName__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnName__tp_dealloc(PyNs3NdnName *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnName_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnName_wrapper_registry.end()) {
        PyNs3NdnName_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::Name *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3NdnName__tp_str(PyNs3NdnName *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3NdnName__tp_richcompare (PyNs3NdnName *PYBINDGEN_UNUSED(self), PyNs3NdnName *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnName_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        if (*self->obj < *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_LE:
        if (*self->obj <= *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_EQ:
        if (*self->obj == *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_NE:
        if (*self->obj != *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_GE:
        if (*self->obj >= *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_GT:
        if (*self->obj > *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}


static void
PyNs3NdnName_Iter__tp_clear(PyNs3NdnName_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
PyNs3NdnName_Iter__tp_traverse(PyNs3NdnName_Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_PyNs3NdnName_Iter__tp_dealloc(PyNs3NdnName_Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_PyNs3NdnName__tp_iter(PyNs3NdnName *self)
{
    PyNs3NdnName_Iter *iter = PyObject_GC_New(PyNs3NdnName_Iter, &PyNs3NdnName_IterType);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new ns3::ndn::Name::const_iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_PyNs3NdnName_Iter__tp_iter(PyNs3NdnName_Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_PyNs3NdnName_Iter__tp_iternext(PyNs3NdnName_Iter *self)
{
    PyObject *py_retval;
    ns3::ndn::Name::const_iterator iter;
    PyNs3NdnNameComponent *py_Component;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_Component = PyObject_New(PyNs3NdnNameComponent, &PyNs3NdnNameComponent_Type);
    py_Component->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Component->obj = new ns3::ndn::name::Component((*iter));
    PyNs3NdnNameComponent_wrapper_registry[(void *) py_Component->obj] = (PyObject *) py_Component;
    py_retval = Py_BuildValue((char *) "N", py_Component);
    return py_retval;
}
PyTypeObject PyNs3NdnName_IterType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.NameIter",            /* tp_name */
    sizeof(PyNs3NdnName_Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnName_Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3NdnName_Iter__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3NdnName_Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnName_Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_PyNs3NdnName_Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject PyNs3NdnName_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.Name",            /* tp_name */
    sizeof(PyNs3NdnName),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnName__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)_wrap_PyNs3NdnName__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnName__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_PyNs3NdnName__tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnName_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnName__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnInterest_wrapper_registry;


static int
_wrap_PyNs3NdnInterest__tp_init__0(PyNs3NdnInterest *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *interest;
    ns3::ndn::Interest interest2;
    const char *keywords[] = {"interest", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &interest)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (PyObject_IsInstance(interest, (PyObject*) &PyNs3NdnInterest_Type)) {
        interest2 = *((PyNs3NdnInterest *) interest)->obj;
    } else if (PyObject_IsInstance(interest, (PyObject*) &PyNs3NdnName_Type)) {
        interest2 = *((PyNs3NdnName *) interest)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Interest, Name), not %s", Py_TYPE(interest)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ndn::Interest(interest2);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3NdnInterest__tp_init__1(PyNs3NdnInterest *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ndn::Interest();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3NdnInterest__tp_init(PyNs3NdnInterest *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3NdnInterest__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnInterest__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


static PyObject*
_wrap_PyNs3NdnInterest__copy__(PyNs3NdnInterest *self)
{

    PyNs3NdnInterest *py_copy;
    py_copy = PyObject_New(PyNs3NdnInterest, &PyNs3NdnInterest_Type);
    py_copy->obj = new ns3::ndn::Interest(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3NdnInterest_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3NdnInterest_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3NdnInterest__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnInterest__tp_dealloc(PyNs3NdnInterest *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnInterest_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnInterest_wrapper_registry.end()) {
        PyNs3NdnInterest_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::Interest *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3NdnInterest__tp_str(PyNs3NdnInterest *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3NdnInterest__tp_richcompare (PyNs3NdnInterest *PYBINDGEN_UNUSED(self), PyNs3NdnInterest *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnInterest_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnInterest_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.Interest",            /* tp_name */
    sizeof(PyNs3NdnInterest),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnInterest__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)_wrap_PyNs3NdnInterest__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnInterest__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnInterest_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnInterest__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnData_wrapper_registry;


static int
_wrap_PyNs3NdnData__tp_init__0(PyNs3NdnData *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3NdnData *data;
    const char *keywords[] = {"data", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NdnData_Type, &data)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ndn::Data(*((PyNs3NdnData *) data)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3NdnData__tp_init__1(PyNs3NdnData *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ndn::Data();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3NdnData__tp_init(PyNs3NdnData *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3NdnData__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NdnData__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


static PyObject*
_wrap_PyNs3NdnData__copy__(PyNs3NdnData *self)
{

    PyNs3NdnData *py_copy;
    py_copy = PyObject_New(PyNs3NdnData, &PyNs3NdnData_Type);
    py_copy->obj = new ns3::ndn::Data(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3NdnData_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3NdnData_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3NdnData__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnData__tp_dealloc(PyNs3NdnData *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnData_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3NdnData_wrapper_registry.end()) {
        PyNs3NdnData_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ndn::Data *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3NdnData__tp_str(PyNs3NdnData *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3NdnData__tp_richcompare (PyNs3NdnData *PYBINDGEN_UNUSED(self), PyNs3NdnData *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnData_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnData_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.Data",            /* tp_name */
    sizeof(PyNs3NdnData),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnData__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)_wrap_PyNs3NdnData__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnData__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnData_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnData__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnFace_wrapper_registry;

static int
_wrap_PyNs3NdnFace__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'Face' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3NdnFace_getId(PyNs3NdnFace *self)
{
    PyObject *py_retval;
    int64_t retval;
    
    retval = self->obj->getId();
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}

static PyMethodDef PyNs3NdnFace_methods[] = {
    {(char *) "getId", (PyCFunction) _wrap_PyNs3NdnFace_getId, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnFace__tp_dealloc(PyNs3NdnFace *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnFace_wrapper_registry.find((void *) self->obj.get());
    if (wrapper_lookup_iter != PyNs3NdnFace_wrapper_registry.end()) {
        PyNs3NdnFace_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    self->obj.~shared_ptr< ns3::ndn::Face >();
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3NdnFace__tp_str(PyNs3NdnFace *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3NdnFace__tp_richcompare (PyNs3NdnFace *PYBINDGEN_UNUSED(self), PyNs3NdnFace *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnFace_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnFace_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.Face",            /* tp_name */
    sizeof(PyNs3NdnFace),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnFace__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)_wrap_PyNs3NdnFace__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnFace__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnFace_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnFace__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3NdnFaceContainer_wrapper_registry;

static int
_wrap_PyNs3NdnFaceContainer__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'FaceContainer' cannot be constructed ()");
    return -1;
}

static PyMethodDef PyNs3NdnFaceContainer_methods[] = {
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3NdnFaceContainer__tp_dealloc(PyNs3NdnFaceContainer *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3NdnFaceContainer_wrapper_registry.find((void *) ::ns3::PeekPointer(self->obj));
    if (wrapper_lookup_iter != PyNs3NdnFaceContainer_wrapper_registry.end()) {
        PyNs3NdnFaceContainer_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    self->obj.~Ptr< ns3::ndn::FaceContainer >();
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NdnFaceContainer__tp_richcompare (PyNs3NdnFaceContainer *PYBINDGEN_UNUSED(self), PyNs3NdnFaceContainer *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NdnFaceContainer_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3NdnFaceContainer_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "ndnSIM.ndn.FaceContainer",            /* tp_name */
    sizeof(PyNs3NdnFaceContainer),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NdnFaceContainer__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NdnFaceContainer__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NdnFaceContainer_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NdnFaceContainer__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef ndnSIM_ndn_moduledef = {
    PyModuleDef_HEAD_INIT,
    "ndnSIM.ndn",
    NULL,
    -1,
    ndnSIM_ndn_functions,
};
#endif

static PyObject *
initndnSIM_ndn(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&ndnSIM_ndn_moduledef);
    #else
    m = Py_InitModule3((char *) "ndnSIM.ndn", ndnSIM_ndn_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "_PyNs3NdnStackHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnStackHelper_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::StackHelper' class */
    if (PyType_Ready(&PyNs3NdnStackHelper_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "StackHelper", (PyObject *) &PyNs3NdnStackHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnFibHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnFibHelper_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::FibHelper' class */
    if (PyType_Ready(&PyNs3NdnFibHelper_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "FibHelper", (PyObject *) &PyNs3NdnFibHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnStrategyChoiceHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnStrategyChoiceHelper_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::StrategyChoiceHelper' class */
    if (PyType_Ready(&PyNs3NdnStrategyChoiceHelper_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "StrategyChoiceHelper", (PyObject *) &PyNs3NdnStrategyChoiceHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnAppHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnAppHelper_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::AppHelper' class */
    if (PyType_Ready(&PyNs3NdnAppHelper_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "AppHelper", (PyObject *) &PyNs3NdnAppHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnGlobalRoutingHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnGlobalRoutingHelper_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::GlobalRoutingHelper' class */
    if (PyType_Ready(&PyNs3NdnGlobalRoutingHelper_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "GlobalRoutingHelper", (PyObject *) &PyNs3NdnGlobalRoutingHelper_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ndn::L3Protocol), &PyNs3NdnL3Protocol_Type);
    /* Register the 'ns3::ndn::L3Protocol' class */
    PyNs3NdnL3Protocol_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3NdnL3Protocol_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "L3Protocol", (PyObject *) &PyNs3NdnL3Protocol_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnName_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnName_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::Name' class */
    if (PyType_Ready(&PyNs3NdnName_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Name", (PyObject *) &PyNs3NdnName_Type);
    /* Register the 'ns3::ndn::Name' class iterator*/
    if (PyType_Ready(&PyNs3NdnName_IterType)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "NameIter", (PyObject *) &PyNs3NdnName_IterType);
    PyModule_AddObject(m, (char *) "_PyNs3NdnInterest_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnInterest_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::Interest' class */
    if (PyType_Ready(&PyNs3NdnInterest_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Interest", (PyObject *) &PyNs3NdnInterest_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnData_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnData_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::Data' class */
    if (PyType_Ready(&PyNs3NdnData_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Data", (PyObject *) &PyNs3NdnData_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnFace_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnFace_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::Face' class */
    if (PyType_Ready(&PyNs3NdnFace_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Face", (PyObject *) &PyNs3NdnFace_Type);
    PyModule_AddObject(m, (char *) "_PyNs3NdnFaceContainer_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3NdnFaceContainer_wrapper_registry, NULL));
    /* Register the 'ns3::ndn::FaceContainer' class */
    if (PyType_Ready(&PyNs3NdnFaceContainer_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "FaceContainer", (PyObject *) &PyNs3NdnFaceContainer_Type);
    submodule = initndnSIM_ndn_name();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "name", submodule);
    submodule = initndnSIM_ndn_nfd();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "nfd", submodule);
    return m;
}
static PyMethodDef ndnSIM_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3ObjectBase_Type;
std::map<void*, PyObject*> *_PyNs3ObjectBase_wrapper_registry;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter_Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map;


PyTypeObject *_PyNs3Object_Type;


PyTypeObject *_PyNs3TypeId_Type;
std::map<void*, PyObject*> *_PyNs3TypeId_wrapper_registry;


PyTypeObject *_PyNs3AttributeValue_Type;
std::map<void*, PyObject*> *_PyNs3AttributeValue_wrapper_registry;


PyTypeObject *_PyNs3NodeContainer_Type;
std::map<void*, PyObject*> *_PyNs3NodeContainer_wrapper_registry;


PyTypeObject *_PyNs3Node_Type;


PyTypeObject *_PyNs3ApplicationContainer_Type;
std::map<void*, PyObject*> *_PyNs3ApplicationContainer_wrapper_registry;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef ndnSIM_moduledef = {
    PyModuleDef_HEAD_INIT,
    "ndnSIM",
    NULL,
    -1,
    ndnSIM_functions,
};
#endif


#if PY_VERSION_HEX >= 0x03000000
    #define MOD_ERROR NULL
    #define MOD_INIT(name) PyObject* PyInit_##name(void)
    #define MOD_RETURN(val) val
#else
    #define MOD_ERROR
    #define MOD_INIT(name) void init##name(void)
    #define MOD_RETURN(val)
#endif
#if defined(__cplusplus)
extern "C"
#endif
#if defined(__GNUC__) && __GNUC__ >= 4
__attribute__ ((visibility("default")))
#endif


MOD_INIT(ndnSIM)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&ndnSIM_moduledef);
    #else
    m = Py_InitModule3((char *) "ndnSIM", ndnSIM_functions, NULL);
    #endif
    if (m == NULL) {
        return MOD_ERROR;
    }
    PyModule_AddIntConstant(m, (char *) "STD_IOS_IN", std::ios::in);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_OUT", std::ios::out);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_ATE", std::ios::ate);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_APP", std::ios::app);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_TRUNC", std::ios::trunc);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_BINARY", std::ios::binary);
    /* Import the 'ns3::ObjectBase' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ObjectBase_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ObjectBase");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ObjectBase_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ObjectBase_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ObjectBase_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::Object, ns3::ObjectBase, ns3::ObjectDeleter >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::Object, ns3::ObjectBase, ns3::ObjectDeleter >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Object' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Object_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Object");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::TypeId' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TypeId_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TypeId");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TypeId_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TypeId_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TypeId_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::AttributeValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AttributeValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AttributeValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3AttributeValue_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3AttributeValue_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3AttributeValue_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::NodeContainer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NodeContainer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NodeContainer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3NodeContainer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3NodeContainer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3NodeContainer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Node' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Node_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Node");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ApplicationContainer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ApplicationContainer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ApplicationContainer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ApplicationContainer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ApplicationContainer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ApplicationContainer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    submodule = initndnSIM_ndn();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "ndn", submodule);
    return MOD_RETURN(m);
}
