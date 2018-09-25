// ʵ�����ǵ� native����
#include "com_novate_ndk12_NdkSimple.h" // ��������Լ����ɵ�ͷ�ļ�

// �����µ� ͷ�ļ�
#include "com_novate_ndk12_NdkSimple1.h"

// JNIEXPORT: ��jni������һ���ؼ��֣������٣�������ͨ��������������eclipse����ʱ�ᱨ��
// �����ǣ��������������Ա��ⲿ����

// jstring: ����java�е� String������ jint��jboolean�ȣ�
// JNICALL: ��һ���ؼ��֣������ٵģ�������������Ǹ� jni���õģ�
// JNIEnv: ����� c��java�໥���õ� ������ѧϰjni��ֻ��Ҫ�� JNIEnv�����еķ���������Ϳ��ԣ�
// jobject: java���ݹ����Ķ��󣬾��Ǳ���Ŀ�е� NdkSimple.java ����
// jclass:  java����������class ���󣬾��Ǳ���Ŀ�е� NdkSimple.class ����
// ->������ һ��ָ����ʹ�ã������� ����ָ����ʹ�ã�������ã���ֻ�������·�ʽ����ͨ��*����ȡֵ��ȡ����ֵ��һ��ָ�룬�Ϳ����� ->���÷�����
JNIEXPORT jstring JNICALL Java_com_novate_ndk12_NdkSimple_getSignaturePwd
(JNIEnv * env, jobject jobj){

	// JNIEnv *: ������ env����������˼һ�����Ƕ���ָ�룻
	// ->: ֻ����һ��ָ��ſ����ã����ϱ��������Ƕ���ָ�룬����ʹ��->��
	// ������*env: *env��ʾ���������ָ��ȡֵ������ֵ����һ��ָ��, ���ʱ��Ϳ���ʹ�� ->�ˣ�Ȼ��Ϳ��Ե���NewStringUTF()������ ;
	return (*env)->NewStringUTF(env , "123456");
}

// c�з���java�е�һ������
JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_changeName
(JNIEnv *env, jobject jobj){
	// �����ǣ���ȡjava�����е� ��ȡname���ԣ�Ȼ���޸�Ϊ Jack
	// ֪������󣺴�������д��
	
	// 3. ��ȡ jclass
	jclass j_clz = (*env)->GetObjectClass(env,jobj);


	// �ڷ����ϱߣ��Ҽ�ת�����壬�Ϳ����ҵ�����Ҫ���ݵĲ���
	// 2. ��ȡ jfiled   (JNIEnv *env, jclass clazz, const char *name, const char *sig);
	// clazz: java�е�class
	// name: ��ȡ�ĸ����Ե������� ���������Ծ���java�����е� name����
	// sig: ���Ե�ǩ����ͨ������
	jfieldID j_fid = (*env)->GetFieldID(env, j_clz, "name", "Ljava/lang/String;");


	// 1. ��ȡ name���ԣ�����ȱ��filed
	jstring j_str = (*env)->GetObjectField(env, jobj, j_fid);

	// ��ȡ�� j_str�ַ���֮�󣬴�ӡ�ַ�����
	// �� jstring�ַ���תΪ c���ַ���c_str��env�� java��c������
	char *c_str = (*env)->GetStringUTFChars(env , j_str , NULL);

	printf("name is %s" , c_str);


	// Ȼ���޸�nameֵΪ Jack
	jstring jackName = (*env)->NewStringUTF(env , "Jackc");
	(*env)->SetObjectField(env , jobj , j_fid , jackName);

	// Ȼ�� ���� - �������ɽ��������Ȼ������java����

	// java�������н������
	// "�޸�ǰ��" Novate
	// "�޸ĺ�" Jack
}


// c�з���java�еľ�̬����
JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_changeAge
(JNIEnv *env, jclass jcls){
	// �����ǣ��� native��� age �޸�Ϊ 36

	// 2. Ȼ���ȡ fieldID  (JNIEnv *env, jclass clazz, const char *name, const char *sig);
	jfieldID j_fid = (*env)->GetStaticFieldID(env , jcls , "age" , "I");
	// 1. ���Ȼ�ȡԭ����age����ȡ��̬������  (JNIEnv *env, jclass clazz, jfieldID fieldID);
	jint age = (*env)->GetStaticIntField(env, jcls, j_fid);

	// �޸�ԭ��age��Ϊ 24+12 = 36
	age += 12;

	// �����µ�age����  (JNIEnv *env, jclass clazz, jfieldID fieldID, jint value);
	(*env)->SetStaticIntField(env , jcls , j_fid , age);
	
	// ���д���֮ǰ��һ��Ҫע�⣺���� - �������ɽ��������Ȼ������java����

	// java�������н������
	// "�޸�ǰ��" 24
	// "�޸ĺ�" 36
}



JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_callAddMathod
(JNIEnv * env, jobject jobj){

	// �����ǣ�����java�ķ�������������д


	// 3. ��ȡjclass
	jclass j_clz = (*env)->GetObjectClass(env , jobj);

	// 2. ��ȡjmethodID  (JNIEnv *env, jclass clazz, const char *name, const char *sig);
	// char *name: ���������� add
	// char *sig: ������ǩ�� (II)I

	jmethodID j_mid = (*env)->GetMethodID(env, j_clz , "add", "(II)I");

	
	// 1. ����û�з���ֵ�ķ�����(JNIEnv *env, jobject obj, jmethodID methodID, ...);
	// (JNIEnv *env, jobject obj, jmethodID methodID, ...) ...Ϊ�ɱ����������Ҫ�����2������3������
	jint sum = (*env)->CallIntMethod(env, jobj, j_mid , 2,3);

	printf("sum = %d" , sum);

	// д��c�����һ��Ҫ ���� - �������ɽ��������Ȼ������java����

	// java���� ���н����
	// sum = 5
}