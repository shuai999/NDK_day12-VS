#include<stdlib.h>
#include<stdio.h>
// ����һ���ṹ��ָ��ı���
typedef const struct JNINativeInterface_ *JNIEnv;

// 1. ģ��һ���ṹ��
struct JNINativeInterface{
	// ����ṹ�巽��ָ��
	// ����ֵ����(��������)(���������ͣ���Ҫ��������)
	char*(*NewStringUTF)(JNIEnv* , char*)
};

char* NewStringUTF(JNIEnv *env , char *c_str){
	// �� c_stringתΪ java�е� jstring
	return c_str;
}

char*  Java_com_novate_getSignaturePwd(JNIEnv * env){

	return (*env)->NewStringUTF(env, "123456");
}


void main(){

	// ���� JNIEnv* �Ķ���
	struct JNINativeInterface nativeInterface;
	// �� �ṹ�巽��ָ�븳ֵ��������ʵ�ַ���
	nativeInterface.NewStringUTF = NewStringUTF;

	// ���� Java_com_novate_ndk12_NdkSimple_getSignaturePwd �Ĳ����� JNIEnv*
	JNIEnv env = &nativeInterface; // env��һ��ָ��
	JNIEnv *jniEnv = &env; // *jniEnv������ָ��

	// �� jniEnv���� ���ݸ�Java_com_novate_getSignaturePwd����

	char* jstring = Java_com_novate_getSignaturePwd(jniEnv);

	// �� jstring ͨ�� JNIEnv�������ݸ�java��
	printf("jstring = %s" , jstring);

	// ��������ʱ����Ҫ�Ѹղ����ɵĶ�̬��dll�޸�Ϊ exe��Ȼ�� ���� -> �������ɽ������

	getchar();
}
