#include<stdlib.h>
#include<stdio.h>
// 定义一个结构体指针的别名
typedef const struct JNINativeInterface_ *JNIEnv;

// 1. 模拟一个结构体
struct JNINativeInterface{
	// 定义结构体方法指针
	// 返回值类型(方法名称)(方法的类型，不要方法参数)
	char*(*NewStringUTF)(JNIEnv* , char*)
};

char* NewStringUTF(JNIEnv *env , char *c_str){
	// 把 c_string转为 java中的 jstring
	return c_str;
}

char*  Java_com_novate_getSignaturePwd(JNIEnv * env){

	return (*env)->NewStringUTF(env, "123456");
}


void main(){

	// 构建 JNIEnv* 的对象
	struct JNINativeInterface nativeInterface;
	// 给 结构体方法指针赋值，就是是实现方法
	nativeInterface.NewStringUTF = NewStringUTF;

	// 传给 Java_com_novate_ndk12_NdkSimple_getSignaturePwd 的参数是 JNIEnv*
	JNIEnv env = &nativeInterface; // env：一级指针
	JNIEnv *jniEnv = &env; // *jniEnv：二级指针

	// 把 jniEnv对象 传递给Java_com_novate_getSignaturePwd方法

	char* jstring = Java_com_novate_getSignaturePwd(jniEnv);

	// 把 jstring 通过 JNIEnv桥梁传递给java层
	printf("jstring = %s" , jstring);

	// 这里运行时，需要把刚才生成的动态库dll修改为 exe；然后 生成 -> 重新生成解决方案

	getchar();
}
