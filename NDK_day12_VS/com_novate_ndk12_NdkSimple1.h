/* DO NOT EDIT THIS FILE - it is machine generated */
#include "jni.h"
/* Header for class com_novate_ndk12_NdkSimple1 */

#ifndef _Included_com_novate_ndk12_NdkSimple1
#define _Included_com_novate_ndk12_NdkSimple1
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_novate_ndk12_NdkSimple1
 * Method:    changeName
 * Signature: ()V
 */
// 由于java中的属性是一般属性，所以这里是 jobject 
JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_changeName
  (JNIEnv *, jobject);

// 如果java中的属性是静态的，这里就是 jclass
JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_changeAge
(JNIEnv *, jclass);


// 只要方法不是静态的，这里就是 jobject，如果是静态的，就是jclass
JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_callAddMathod
(JNIEnv *, jobject);


#ifdef __cplusplus
}
#endif
#endif
