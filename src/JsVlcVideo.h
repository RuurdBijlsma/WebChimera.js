#pragma once

#include <string>

#include <v8.h>
#include <node_object_wrap.h>

class JsVlcPlayer; //#include "JsVlcPlayer.h"

class JsVlcVideo :
        public node::ObjectWrap {
public:
    static void initJsApi();

    static v8::UniquePersistent <v8::Object> create(JsVlcPlayer &player);

    v8::Local <v8::Array> getTracksArray();

    std::string description(uint32_t index);

    unsigned count();

    v8::Local <v8::Array> width();

    v8::Local <v8::Array> height();

    int track();

    void setTrack(unsigned);

    double contrast();

    void setContrast(double);

    double brightness();

    void setBrightness(double);

    int hue();

    void setHue(int);

    double saturation();

    void setSaturation(double);

    double gamma();

    void setGamma(double);

    v8::Local <v8::Object> deinterlace();

private:
    static void jsCreate(const v8::FunctionCallbackInfo <v8::Value> &args);

    JsVlcVideo(v8::Local <v8::Object> &thisObject, JsVlcPlayer *);

private:
    static v8::Persistent <v8::Function> _jsConstructor;

    JsVlcPlayer *_jsPlayer;

    v8::UniquePersistent <v8::Object> _jsDeinterlace;
};
