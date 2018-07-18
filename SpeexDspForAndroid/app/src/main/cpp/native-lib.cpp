#include <jni.h>
#include <string>

#include <speex/speex_preprocess.h>
/* Symbol visibility prefix */
#define EXPORT __attribute__((visibility("default")))

#define FIXED_POINT
#define USE_KISS_FFT
#define HAVE_CONFIG_H
#define HEADLEN 44
#define SAMPLE_RATE   (48000)
#define SAMPLES_PER_FRAME  (1024)
#define FRAME_SIZE   (SAMPLES_PER_FRAME * 1000/ SAMPLE_RATE)
#define FRAME_BYTES  (SAMPLES_PER_FRAME)

extern "C" JNIEXPORT jstring

JNICALL
Java_io_github_sunnybird_speexdspforandroid_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    SpeexPreprocessState *state = speex_preprocess_state_init(1024, SAMPLE_RATE);
    int denoise = 1;
    int noiseSuppress = -25;
    speex_preprocess_ctl(state, SPEEX_PREPROCESS_SET_DENOISE, &denoise);
    speex_preprocess_ctl(state, SPEEX_PREPROCESS_SET_NOISE_SUPPRESS, &noiseSuppress);

    speex_preprocess_state_destroy(state);
    return env->NewStringUTF(hello.c_str());
}
