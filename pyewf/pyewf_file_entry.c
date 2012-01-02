/*
 * Python object definition of the libewf file entry
 *
 * Copyright (c) 2006-2012, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <memory.h>
#include <types.h>

#include <libcstring.h>
#include <liberror.h>

#if defined( HAVE_STDLIB_H )
#include <stdlib.h>
#endif

#include <libewf.h>

#include "pyewf.h"
#include "pyewf_datetime.h"
#include "pyewf_file_entry.h"
#include "pyewf_metadata.h"
#include "pyewf_python.h"

PyMethodDef pyewf_file_entry_object_methods[] = {

	/* Functions to access the file entry data */

	{ "read_buffer",
	  (PyCFunction) pyewf_file_entry_read_buffer,
	  METH_VARARGS | METH_KEYWORDS,
	  "Reads a buffer of file entry data from EWF file(s)" },

	{ "read_random",
	  (PyCFunction) pyewf_file_entry_read_random,
	  METH_VARARGS | METH_KEYWORDS,
	  "Reads a buffer of file entry data at a specific offset from EWF file(s)" },

	{ "seek_offset",
	  (PyCFunction) pyewf_file_entry_seek_offset,
	  METH_VARARGS | METH_KEYWORDS,
	  "Seeks an offset within the file entry data" },

	{ "get_offset",
	  (PyCFunction) pyewf_file_entry_get_offset,
	  METH_NOARGS,
	  "Returns the current offset within the file entry data" },

	/* Some Pythonesque aliases */

	{ "read",
	  (PyCFunction) pyewf_file_entry_read_buffer,
	  METH_VARARGS | METH_KEYWORDS,
	  "Reads a buffer of file entry data from EWF file(s)" },

	{ "seek",
	  (PyCFunction) pyewf_file_entry_seek_offset,
	  METH_VARARGS | METH_KEYWORDS,
	  "Seeks an offset within the file entry data" },

	{ "tell",
	  (PyCFunction) pyewf_file_entry_get_offset,
	  METH_NOARGS,
	  "Returns the current offset within the file entry data" },

	/* Functions to access the metadata */

	{ "get_size",
	  (PyCFunction) pyewf_file_entry_get_size,
	  METH_NOARGS,
	  "Returns the size of the file entry data" },

	{ "get_creation_time",
	  (PyCFunction) pyewf_file_entry_get_creation_time,
	  METH_NOARGS,
	  "Returns the creation date and time of the file entry" },

	{ "get_modification_time",
	  (PyCFunction) pyewf_file_entry_get_modification_time,
	  METH_NOARGS,
	  "Returns the modification date and time of the file entry" },

	{ "get_access_time",
	  (PyCFunction) pyewf_file_entry_get_access_time,
	  METH_NOARGS,
	  "Returns the access date and time of the file entry" },

	{ "get_entry_modification_time",
	  (PyCFunction) pyewf_file_entry_get_entry_modification_time,
	  METH_NOARGS,
	  "Returns the entry modification date and time of the file entry" },

	{ "get_name",
	  (PyCFunction) pyewf_file_entry_get_name,
	  METH_NOARGS,
	  "Returns the name of the file entry" },

	{ "get_hash_value_md5",
	  (PyCFunction) pyewf_file_entry_get_hash_value_md5,
	  METH_NOARGS,
	  "Retrieves the MD5 hash of the file entry data" },

	/* Functions to access the sub file entries */

	{ "get_number_of_sub_file_entries",
	  (PyCFunction) pyewf_file_entry_get_number_of_sub_file_entries,
	  METH_NOARGS,
	  "Retrieves the number of sub file entries" },

	{ "get_sub_file_entry",
	  (PyCFunction) pyewf_file_entry_get_sub_file_entry,
	  METH_VARARGS | METH_KEYWORDS,
	  "Retrieves a specific sub file entry" },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyTypeObject pyewf_file_entry_type_object = {
	PyObject_HEAD_INIT( NULL )

	/* ob_size */
	0,
	/* tp_name */
	"pyewf.file_entry",
	/* tp_basicsize */
	sizeof( pyewf_file_entry_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyewf_file_entry_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
        /* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyewf file entry object (wraps libewf_file_entry_t)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	pyewf_file_entry_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyewf_file_entry_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new pyewf file_entry object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyewf_file_entry_new(
           PyObject *self )
{
	static char *function                = "pyewf_file_entry_new";
	pyewf_file_entry_t *pyewf_file_entry = NULL;

	pyewf_file_entry = PyObject_New(
	                    struct pyewf_file_entry,
	                    &pyewf_file_entry_type_object );

	if( pyewf_file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize file_entry.",
		 function );

		goto on_error;
	}
	if( pyewf_file_entry_init(
	     pyewf_file_entry ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize file_entry.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pyewf_file_entry );

on_error:
	if( pyewf_file_entry != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyewf_file_entry );
	}
	return( NULL );
}

/* Intializes a file_entry object
 * Returns 0 if successful or -1 on error
 */
int pyewf_file_entry_init(
     pyewf_file_entry_t *pyewf_file_entry )
{
	static char *function = "pyewf_file_entry_init";

	if( pyewf_file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file_entry.",
		 function );

		return( -1 );
	}
	/* Make sure libewf file_entry is set to NULL
	 */
	pyewf_file_entry->file_entry = NULL;

	return( 0 );
}

/* Frees a file_entry object
 */
void pyewf_file_entry_free(
      pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error = NULL;
	static char *function   = "pyewf_file_entry_free";

	if( pyewf_file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file_entry.",
		 function );

		return;
	}
	if( pyewf_file_entry->ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file_entry - missing ob_type.",
		 function );

		return;
	}
	if( pyewf_file_entry->ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file_entry - invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	if( pyewf_file_entry->file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file_entry - missing libewf file_entry.",
		 function );

		return;
	}
	if( libewf_file_entry_free(
	     &( pyewf_file_entry->file_entry ),
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_MemoryError,
			 "%s: unable to free file_entry.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_MemoryError,
			 "%s: unable to free file_entry.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );
	}
	pyewf_file_entry->ob_type->tp_free(
	 (PyObject*) pyewf_file_entry );
}

/* Reads a buffer of file entry data from EWF file(s)
 * Returns a Python object holding the data if successful or NULL on error
 */
PyObject *pyewf_file_entry_read_buffer(
           pyewf_file_entry_t *pyewf_file_entry,
           PyObject *arguments,
           PyObject *keywords )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error     = NULL;
	PyObject *result_data       = NULL;
	static char *function       = "pyewf_file_entry_read_buffer";
	static char *keyword_list[] = { "size", NULL };
	ssize_t read_count          = 0;
	int read_size               = -1;

	if( pyewf_file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid pyewf file_entry.",
		 function );

		return( NULL );
	}
	if( pyewf_file_entry->file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid pyewf file_entry - missing libewf file_entry.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "|i",
	     keyword_list,
	     &read_size ) == 0 )
	{
		return( NULL );
	}
	if( read_size < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read size value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	if( read_size > INT_MAX )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read size value exceeds maximum.",
		 function );

		return( NULL );
	}
	result_data = PyString_FromStringAndSize(
	               NULL,
	               read_size );

	read_count = libewf_file_entry_read_buffer(
	              pyewf_file_entry->file_entry,
	              PyString_AsString(
	               result_data ),
	              (size_t) read_size,
	              &error );

	if( read_count != (ssize_t) read_size )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to read data.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to read data.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	return( result_data );
}

/* Reads a buffer of file entry data at a specific offset from EWF file(s)
 * Returns a Python object holding the data if successful or NULL on error
 */
PyObject *pyewf_file_entry_read_random(
           pyewf_file_entry_t *pyewf_file_entry,
           PyObject *arguments,
           PyObject *keywords )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error     = NULL;
	PyObject *result_data       = NULL;
	static char *function       = "pyewf_file_entry_read_random";
	static char *keyword_list[] = { "size", "offset", NULL };
	off64_t read_offset         = 0;
	ssize_t read_count          = 0;
	int read_size               = 0;

	if( pyewf_file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid pyewf file_entry.",
		 function );

		return( NULL );
	}
	if( pyewf_file_entry->file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid pyewf file_entry - missing libewf file_entry.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "i|L",
	     keyword_list,
	     &read_size,
	     &read_offset ) == 0 )
	{
		return( NULL );
	}
	if( read_size < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read size value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	if( read_size > INT_MAX )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read size value exceeds maximum.",
		 function );

		return( NULL );
	}
	if( read_offset < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read offset value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	result_data = PyString_FromStringAndSize(
	               NULL,
	               read_size );

	read_count = libewf_file_entry_read_random(
	              pyewf_file_entry->file_entry,
	              PyString_AsString(
	               result_data ),
	              (size_t) read_size,
	              (off64_t) read_offset,
	              &error );

	if( read_count != (ssize_t) read_size )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to read data.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to read data.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	return( result_data );
}

/* Seeks a certain offset in the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_seek_offset(
           pyewf_file_entry_t *pyewf_file_entry,
           PyObject *arguments,
           PyObject *keywords )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error     = NULL;
	static char *function       = "pyewf_file_entry_seek_offset";
	static char *keyword_list[] = { "offset", "whence", NULL };
	off64_t offset              = 0;
	int whence                  = 0;

	if( pyewf_file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid pyewf file_entry.",
		 function );

		return( NULL );
	}
	if( pyewf_file_entry->file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid pyewf file_entry - missing libewf file_entry.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "L|i",
	     keyword_list, 
	     &offset,
	     &whence ) == 0 )
	{
		return( NULL );
	}
	if( libewf_file_entry_seek_offset(
	     pyewf_file_entry->file_entry,
	     offset,
	     whence,
	     &error ) < 0 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to seek offset.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to seek offset.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	return( Py_None );
}

/* Retrieves the current offset in the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_offset(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error = NULL;
	static char *function   = "pyewf_file_entry_get_offset";
	off64_t current_offset  = 0;

	if( libewf_file_entry_get_offset(
	     pyewf_file_entry->file_entry,
	     &current_offset,
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve offset.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve offset.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	return( PyLong_FromLongLong(
	         current_offset ) );
}

/* Retrieves the size of the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_size(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error = NULL;
	static char *function   = "pyewf_file_entry_get_size";
	size64_t size           = 0;

	if( libewf_file_entry_get_size(
	     pyewf_file_entry->file_entry,
	     &size,
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve size.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve size.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	return( PyLong_FromLongLong(
	         size ) );
}

/* Retrieves the creation date and time of the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_creation_time(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error    = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyewf_file_entry_get_creation_time";
	uint32_t posix_time        = 0;

	if( libewf_file_entry_get_creation_time(
	     pyewf_file_entry->file_entry,
	     &posix_time,
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve creation time.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve creation time.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyewf_datetime_new_from_posix_time(
	                    posix_time );

	return( date_time_object );
}

/* Retrieves the modification date and time of the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_modification_time(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error    = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyewf_file_entry_get_modification_time";
	uint32_t posix_time        = 0;

	if( libewf_file_entry_get_modification_time(
	     pyewf_file_entry->file_entry,
	     &posix_time,
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve modification time.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve modification time.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyewf_datetime_new_from_posix_time(
	                    posix_time );

	return( date_time_object );
}

/* Retrieves the access date and time of the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_access_time(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error    = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyewf_file_entry_get_access_time";
	uint32_t posix_time        = 0;

	if( libewf_file_entry_get_access_time(
	     pyewf_file_entry->file_entry,
	     &posix_time,
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve access time.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve access time.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyewf_datetime_new_from_posix_time(
	                    posix_time );

	return( date_time_object );
}

/* Retrieves the entry modification date and time of the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_entry_modification_time(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error    = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyewf_file_entry_get_entry_modification_time";
	uint32_t posix_time        = 0;

	if( libewf_file_entry_get_entry_modification_time(
	     pyewf_file_entry->file_entry,
	     &posix_time,
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve entry modification time.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve entry modification time.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyewf_datetime_new_from_posix_time(
	                    posix_time );

	return( date_time_object );
}

/* Retrieves the name of the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_name(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error = NULL;
	PyObject *string_object = NULL;
	static char *function   = "pyewf_file_entry_get_name";
	const char *errors      = NULL;
	char *name              = NULL;
	size_t name_size        = 0;
	int result              = 0;

	result = libewf_file_entry_get_utf8_name_size(
	          pyewf_file_entry->file_entry,
	          &name_size,
	          &error );

	if( result == -1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve UTF-8 name size.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve UTF-8 name size.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		goto on_error;
	}
	/* Check if the name present
	 */
	else if( ( result == 0 )
	      || ( name_size == 0 ) )
	{
		return( Py_None );
	}
	name = (char *) memory_allocate(
	                 sizeof( char ) * name_size );

	if( name == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create name.",
		 function );

		return( NULL );
	}
	result = libewf_file_entry_get_utf8_name(
	          pyewf_file_entry->file_entry,
	          (uint8_t *) name,
	          name_size,
	          &error );

	if( result == -1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve UTF-8 name.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve UTF-8 name.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		goto on_error;
	}
	/* Check if the name present
	 */
	else if( result == 0 )
	{
		memory_free(
		 name );

		return( Py_None );
	}
	string_object = PyUnicode_DecodeUTF8(
	                 name,
	                 (Py_ssize_t) name_size,
	                 errors );

	if( string_object == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to convert UTF-8 name into Unicode.",
		 function );

		goto on_error;
	}
	memory_free(
	 name );

	return( string_object );

on_error:
	if( name != NULL )
	{
		memory_free(
		 name );
	}
	return( NULL );
}

/* Retrieves the MD5 hash of the file entry data
 * Returns a Python object holding the offset if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_hash_value_md5(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error = NULL;
	PyObject *string_object = NULL;
	static char *function   = "pyewf_file_entry_get_hash_value_md5";
	const char *errors      = NULL;
	char *hash_value        = NULL;
	size_t hash_value_size  = 33;
	int result              = 0;

	hash_value = (char *) memory_allocate(
	                       sizeof( char ) * hash_value_size );

	if( hash_value == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create hash value.",
		 function );

		return( NULL );
	}
	result = libewf_file_entry_get_utf8_hash_value_md5(
	          pyewf_file_entry->file_entry,
	          (uint8_t *) hash_value,
	          hash_value_size,
	          &error );

	if( result == -1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve UTF-8 MD5 hash value.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve UTF-8 MD5 hash value.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		goto on_error;
	}
	/* Check if the hash value is present
	 */
	else if( result == 0 )
	{
		memory_free(
		 hash_value );

		return( Py_None );
	}
	string_object = PyUnicode_DecodeUTF8(
	                 hash_value,
	                 (Py_ssize_t) hash_value_size,
	                 errors );

	if( string_object == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to convert UTF-8 MD5 hash value into Unicode.",
		 function );

		goto on_error;
	}
	memory_free(
	 hash_value );

	return( string_object );

on_error:
	if( hash_value != NULL )
	{
		memory_free(
		 hash_value );
	}
	return( NULL );
}

/* Retrieves the number of sub file entries
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_number_of_sub_file_entries(
           pyewf_file_entry_t *pyewf_file_entry )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error        = NULL;
	static char *function          = "pyewf_file_entry_get_number_of_sub_file_entries";
	int number_of_sub_file_entries = 0;

	if( pyewf_file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file entry.",
		 function );

		return( NULL );
	}
	if( libewf_file_entry_get_number_of_sub_file_entries(
	     pyewf_file_entry->file_entry,
	     &number_of_sub_file_entries,
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve number of sub file entries.",
			 function );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve number of sub file entries.\n%s",
			 function,
			 error_string );
		}
		liberror_error_free(
		 &error );

		return( NULL );
	}
	return( PyInt_FromLong(
	         (long) number_of_sub_file_entries ) );
}

/* Retrieves a specific sub file entry
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyewf_file_entry_get_sub_file_entry(
           pyewf_file_entry_t *pyewf_file_entry,
           PyObject *arguments,
           PyObject *keywords )
{
	char error_string[ PYEWF_ERROR_STRING_SIZE ];

	liberror_error_t *error             = NULL;
	libewf_file_entry_t *sub_file_entry = NULL;
	PyObject *file_entry_object         = NULL;
	static char *keyword_list[]         = { "sub_file_entry_index", NULL };
	static char *function               = "pyewf_file_entry_get_sub_file_entry";
	int sub_file_entry_index            = 0;

	if( pyewf_file_entry == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file entry.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "i",
	     keyword_list,
	     &sub_file_entry_index ) == 0 )
        {
		goto on_error;
        }
	if( libewf_file_entry_get_sub_file_entry(
	     pyewf_file_entry->file_entry,
	     sub_file_entry_index,
	     &sub_file_entry,
	     &error ) != 1 )
	{
		if( liberror_error_backtrace_sprint(
		     error,
		     error_string,
		     PYEWF_ERROR_STRING_SIZE ) == -1 )
                {
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve sub file entry: %d.",
			 function,
			 sub_file_entry_index );
		}
		else
		{
			PyErr_Format(
			 PyExc_IOError,
			 "%s: unable to retrieve sub file entry: %d.\n%s",
			 function,
			 sub_file_entry_index,
			 error_string );
		}
		liberror_error_free(
		 &error );

		goto on_error;
	}
	file_entry_object = pyewf_file_entry_new(
	                     NULL );

	if( file_entry_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create file entry object.",
		 function );

		goto on_error;
	}
	( (pyewf_file_entry_t *) file_entry_object )->file_entry = sub_file_entry;

	return( file_entry_object );

on_error:
	if( sub_file_entry != NULL )
	{
		libewf_file_entry_free(
		 &sub_file_entry,
		 NULL );
	}
	return( NULL );
}

