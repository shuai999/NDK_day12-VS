/* DO NOT EDIT THIS FILE - it is machine generated */
#include "jni.h" // ""表示引入自己的头文件，<>表示引入系统的头文件
/* Header for class com_novate_ndk12_NdkSimple */


// 用来打一个标记，c语言在编译的时候，会把头文件 copy 到你引入的地方，不管是重复引用还是相互引用都只会拷贝一次
// #ifndef和#define表示: 如果没定义，我就定义
#ifndef _Included_com_novate_ndk12_NdkSimple
#define _Included_com_novate_ndk12_NdkSimple

// #ifdef：相当于if语句；#ifdef __cplusplus：如果是c++，统一采用下边的extern "C"的 c的编译方式
#ifdef __cplusplus

// extern "C"：表示不管是 c还是c++，统一采用 c的编译方式，因为在 c里边是不允许函数重载的，但是c++中是可以重载的
extern "C" {
#endif
/*
 * Class:     com_novate_ndk12_NdkSimple
 * Method:    getSignaturePwd
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_novate_ndk12_NdkSimple_getSignaturePwd
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
