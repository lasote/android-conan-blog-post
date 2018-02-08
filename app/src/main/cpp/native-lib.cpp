#include <jni.h>
#include <string>
#include <boost/regex.hpp>
#include <boost/version.hpp>
#include <sstream>


extern "C"
JNIEXPORT jstring

JNICALL
Java_com_jfrog_myboostapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::string line;
    std::stringstream output;
    std::string sentence_with_space = "Boost Rules";

    output << "Using Boost " << (BOOST_VERSION / 100000) << "." << ((BOOST_VERSION / 100) % 1000) << "." << (BOOST_VERSION % 100) << std::endl;

    boost::regex expr("\\w+\\s\\w+");
    if (boost::regex_match(sentence_with_space, expr)) {
        output << "The regex matches! '" << sentence_with_space << "'" << std::endl;
    }
    else{
        output << "The regex doesn't match!" << std::endl;
    }
    return env->NewStringUTF(output.str().c_str());
}
