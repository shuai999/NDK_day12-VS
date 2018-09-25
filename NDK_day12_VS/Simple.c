// 实现我们的 native方法
#include "com_novate_ndk12_NdkSimple.h" // 这个就是自己生成的头文件

// 引入新的 头文件
#include "com_novate_ndk12_NdkSimple1.h"

// JNIEXPORT: 是jni开发的一个关键字，不能少，编译能通过，但是在运行eclipse代码时会报错；
// 作用是：标记这个方法可以被外部调用

// jstring: 代表java中的 String，还有 jint、jboolean等；
// JNICALL: 是一个关键字，可以少的，代表这个方法是给 jni调用的；
// JNIEnv: 这个是 c和java相互调用的 桥梁，学习jni，只需要把 JNIEnv中所有的方法搞清楚就可以；
// jobject: java传递过来的对象，就是本项目中的 NdkSimple.java 对象
// jclass:  java传递下来的class 对象，就是本项目中的 NdkSimple.class 对象
// ->：是在 一级指针中使用，不能在 二级指针中使用，如果想用，就只能用如下方式，先通过*对其取值，取出的值是一级指针，就可以用 ->调用方法了
JNIEXPORT jstring JNICALL Java_com_novate_ndk12_NdkSimple_getSignaturePwd
(JNIEnv * env, jobject jobj){

	// JNIEnv *: 即就是 env，这两个意思一样，是二级指针；
	// ->: 只能是一级指针才可以用，而上边两个都是二级指针，不能使用->；
	// 所以用*env: *env表示对这个二级指针取值，它的值就是一级指针, 这个时候就可以使用 ->了，然后就可以调用NewStringUTF()方法了 ;
	return (*env)->NewStringUTF(env , "123456");
}

// c中访问java中的一般属性
JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_changeName
(JNIEnv *env, jobject jobj){
	// 需求是：获取java代码中的 获取name属性，然后修改为 Jack
	// 知道需求后：从下往上写：
	
	// 3. 获取 jclass
	jclass j_clz = (*env)->GetObjectClass(env,jobj);


	// 在方法上边，右键转到定义，就可以找到所需要传递的参数
	// 2. 获取 jfiled   (JNIEnv *env, jclass clazz, const char *name, const char *sig);
	// clazz: java中的class
	// name: 获取哪个属性的属性名 ，这里属性就是java代码中的 name属性
	// sig: 属性的签名，通过命令
	jfieldID j_fid = (*env)->GetFieldID(env, j_clz, "name", "Ljava/lang/String;");


	// 1. 获取 name属性，这里缺少filed
	jstring j_str = (*env)->GetObjectField(env, jobj, j_fid);

	// 获取到 j_str字符串之后，打印字符串，
	// 把 jstring字符串转为 c的字符串c_str，env是 java和c的桥梁
	char *c_str = (*env)->GetStringUTFChars(env , j_str , NULL);

	printf("name is %s" , c_str);


	// 然后修改name值为 Jack
	jstring jackName = (*env)->NewStringUTF(env , "Jackc");
	(*env)->SetObjectField(env , jobj , j_fid , jackName);

	// 然后 生成 - 重新生成解决方案，然后运行java代码

	// java代码运行结果如下
	// "修改前：" Novate
	// "修改后：" Jack
}


// c中访问java中的静态属性
JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_changeAge
(JNIEnv *env, jclass jcls){
	// 需求是：在 native层把 age 修改为 36

	// 2. 然后获取 fieldID  (JNIEnv *env, jclass clazz, const char *name, const char *sig);
	jfieldID j_fid = (*env)->GetStaticFieldID(env , jcls , "age" , "I");
	// 1. 首先获取原来的age，获取静态的属性  (JNIEnv *env, jclass clazz, jfieldID fieldID);
	jint age = (*env)->GetStaticIntField(env, jcls, j_fid);

	// 修改原来age，为 24+12 = 36
	age += 12;

	// 设置新的age参数  (JNIEnv *env, jclass clazz, jfieldID fieldID, jint value);
	(*env)->SetStaticIntField(env , jcls , j_fid , age);
	
	// 运行代码之前，一定要注意：生成 - 重新生成解决方案，然后运行java代码

	// java代码运行结果如下
	// "修改前：" 24
	// "修改后：" 36
}



JNIEXPORT void JNICALL Java_com_novate_ndk12_NdkSimple1_callAddMathod
(JNIEnv * env, jobject jobj){

	// 需求是：调用java的方法，从下往上写


	// 3. 获取jclass
	jclass j_clz = (*env)->GetObjectClass(env , jobj);

	// 2. 获取jmethodID  (JNIEnv *env, jclass clazz, const char *name, const char *sig);
	// char *name: 方法的名字 add
	// char *sig: 方法的签名 (II)I

	jmethodID j_mid = (*env)->GetMethodID(env, j_clz , "add", "(II)I");

	
	// 1. 调用没有返回值的方法：(JNIEnv *env, jobject obj, jmethodID methodID, ...);
	// (JNIEnv *env, jobject obj, jmethodID methodID, ...) ...为可变参数，是你要计算的2个或者3个参数
	jint sum = (*env)->CallIntMethod(env, jobj, j_mid , 2,3);

	printf("sum = %d" , sum);

	// 写完c代码后，一定要 生成 - 重新生成解决方案，然后运行java代码

	// java代码 运行结果：
	// sum = 5
}