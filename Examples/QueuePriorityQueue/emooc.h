#ifndef EMOOC_H__
#define EMOOC_H__

/************************************************/
/* ���̺귯�� ��� */

#include <stdlib.h> /*C ǥ��, malloc �� ��� ����*/
/************************************************/
/* Ŭ���� Ʋ */

/* Ŭ���� ���� */
#define class_begin(class_name) \
typedef struct class_name class_name; \
typedef struct class_name { \

/* Ŭ���� ����: private�� �ִ� Ŭ���� */
#define class_begin_with_private(class_name) \
typedef struct class_name##_private_seed class_name##_private_seed; \
typedef struct class_name class_name; \
typedef struct class_name {

/* ��� */
#define inherited_from(parent_class_name) \
parent_class_name from_##parent_class_name;

/* Ŭ���� ���� */
#define class_end(class_name) } class_name;

#define class_end_with_private(class_name) \
class_name##_private_seed* private_pointer; } class_name;

/* private ���� */
#define private_begin(class_name) \
typedef struct class_name##_private_seed{

/* private ���� */
#define private_end(class_name) } class_name##_private_seed;

/************************************************/
/* ��� �Լ� ����  */
#define class_func(type, name) type (*name)

/************************************************/
/* ��� �Լ� ������ */

/* ���� */
#define pointer_to_class(class_name) \
class_name *myself_pointer

/***********************************************************************************************************/
/***********************************************************************************************************/
/* ���߿� �߸��� */

/* ���� */
#define member_function_definition_of_the(classname) static
#define class_func_def(type, name) static type name
#define def_class_func(type, name) static type name
#define def_func(type, name) static type name

/***********************************************************************************************************/
/* private ���� */

/* �Լ� ���ο��� private ��� */
#define mk_myself_private(class_name) \
class_name##_private_seed *myself_private_pointer = myself_pointer->private_pointer

/* myself, myself_private */
#define myself (*myself_pointer)
#define myself_private (*myself_private_pointer)
#define private_member (*private_pointer)

/* private ��� �����ϰ� �޸� �Ҵ� */
#define malloc_private(class_name) \
class_name##_private_seed *myself_private_pointer =  (class_name##_private_seed *)malloc(sizeof(class_name##_private_seed)); \
myself_pointer->private_pointer = myself_private_pointer;

#define calloc_private(class_name) \
class_name##_private_seed *myself_private_pointer =  (class_name##_private_seed *)calloc(1, sizeof(class_name##_private_seed)); \
myself_pointer->private_pointer = myself_private_pointer;

/* private free */
#define free_private(class_name) \
free(myself_pointer->private_pointer)

/***********************************************************************************************************/

/************************************************/
/* Ŭ���� �ʱ�ȭ */
#define init_instance {0};

/************************************************/

/**********************************************************************/
/* �ƿ�����Ŭ���� */

#define outline_class_begin(outline_class_name) \
typedef struct outline_class_name outline_class_name; \
typedef struct outline_class_name { \

#define outline_class_end(outline_class_name) \
} outline_class_name;

#define outline_class_func(type, name) type (*name)

/* �������̽��� ��ũ�� ��� */

/**********************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
#endif // ! EMOOC_H__