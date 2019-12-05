#ifndef EMOOC_H__
#define EMOOC_H__

/************************************************/
/* 라이브러리 사용 */

#include <stdlib.h> /*C 표준, malloc 등 사용 위함*/
/************************************************/
/* 클래스 틀 */

/* 클래스 시작 */
#define class_begin(class_name) \
typedef struct class_name class_name; \
typedef struct class_name { \

/* 클래스 시작: private가 있는 클래스 */
#define class_begin_with_private(class_name) \
typedef struct class_name##_private_seed class_name##_private_seed; \
typedef struct class_name class_name; \
typedef struct class_name {

/* 상속 */
#define inherited_from(parent_class_name) \
parent_class_name from_##parent_class_name;

/* 클래스 종료 */
#define class_end(class_name) } class_name;

#define class_end_with_private(class_name) \
class_name##_private_seed* private_pointer; } class_name;

/* private 시작 */
#define private_begin(class_name) \
typedef struct class_name##_private_seed{

/* private 종료 */
#define private_end(class_name) } class_name##_private_seed;

/************************************************/
/* 멤버 함수 선언  */
#define class_func(type, name) type (*name)

/************************************************/
/* 멤버 함수 구현용 */

/* 선언 */
#define pointer_to_class(class_name) \
class_name *myself_pointer

/***********************************************************************************************************/
/***********************************************************************************************************/
/* 나중에 추리자 */

/* 정의 */
#define member_function_definition_of_the(classname) static
#define class_func_def(type, name) static type name
#define def_class_func(type, name) static type name
#define def_func(type, name) static type name

/***********************************************************************************************************/
/* private 관련 */

/* 함수 내부에서 private 사용 */
#define mk_myself_private(class_name) \
class_name##_private_seed *myself_private_pointer = myself_pointer->private_pointer

/* myself, myself_private */
#define myself (*myself_pointer)
#define myself_private (*myself_private_pointer)
#define private_member (*private_pointer)

/* private 사용 가능하게 메모리 할당 */
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
/* 클래스 초기화 */
#define init_instance {0};

/************************************************/

/**********************************************************************/
/* 아웃라인클래스 */

#define outline_class_begin(outline_class_name) \
typedef struct outline_class_name outline_class_name; \
typedef struct outline_class_name { \

#define outline_class_end(outline_class_name) \
} outline_class_name;

#define outline_class_func(type, name) type (*name)

/* 인터페이스는 매크로 사용 */

/**********************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
#endif // ! EMOOC_H__