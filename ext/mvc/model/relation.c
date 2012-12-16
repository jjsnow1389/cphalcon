
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"

/**
 * Phalcon\Mvc\Model\Relation initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Relation){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Relation, mvc_model_relation, phalcon_mvc_model_relation_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_referencedModel"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_fields"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_referencedFields"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_relation_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("BELONGS_TO"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_ONE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("HAS_MANY"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_relation_ce, SL("MANY_TO_MANY"), 3 TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Relation constructor
 */
PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct){

	zval *type, *referenced_model, *fields, *referenced_fields;
	zval *options = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &type, &referenced_model, &fields, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_referencedModel"), referenced_model TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_fields"), fields TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_referencedFields"), referenced_fields TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Relation, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel){


	RETURN_MEMBER(this_ptr, "_referencedModel");
}

PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields){


	RETURN_MEMBER(this_ptr, "_fields");
}

PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields){


	RETURN_MEMBER(this_ptr, "_referencedFields");
}

PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeingKey){

	zval *options;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (phalcon_array_isset_string(options, SS("foreignKey"))) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey){

	zval *options, *foreign_key;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (phalcon_array_isset_string(options, SS("foreignKey"))) {
	
		PHALCON_OBS_VAR(foreign_key);
		phalcon_array_fetch_string(&foreign_key, options, SL("foreignKey"), PH_NOISY_CC);
		if (zend_is_true(foreign_key)) {
			RETURN_CCTOR(foreign_key);
		}
	}
	
	RETURN_MM_FALSE;
}

PHP_METHOD(Phalcon_Mvc_Model_Relation, getQuantity){


	
}

