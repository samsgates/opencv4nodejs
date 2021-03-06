#ifdef HAVE_TRACKING

#include "TrackerCSRTParams.h"

#if CV_MINOR_VERSION > 4 || (CV_MINOR_VERSION == 4 && CV_SUBMINOR_VERSION > 0)

Nan::Persistent<v8::FunctionTemplate> TrackerCSRTParams::constructor;

NAN_MODULE_INIT(TrackerCSRTParams::Init) {
	v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(TrackerCSRTParams::New);
	v8::Local<v8::ObjectTemplate> instanceTemplate = ctor->InstanceTemplate();

	constructor.Reset(ctor);
	ctor->SetClassName(FF_NEW_STRING("TrackerCSRTParams"));
	instanceTemplate->SetInternalFieldCount(1);

	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("admm_iterations"), admm_iterationsGet, admm_iterationsSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("background_ratio"), background_ratioGet, background_ratioSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("cheb_attenuation"), cheb_attenuationGet, cheb_attenuationSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("filter_lr"), filter_lrGet, filter_lrSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("gsl_sigma"), gsl_sigmaGet, gsl_sigmaSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("histogram_bins"), histogram_binsGet, histogram_binsSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("histogram_lr"), histogram_lrGet, histogram_lrSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("hog_clip"), hog_clipGet, hog_clipSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("hog_orientations"), hog_orientationsGet, hog_orientationsSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("kaiser_alpha"), kaiser_alphaGet, kaiser_alphaSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("num_hog_channels_used"), num_hog_channels_usedGet, num_hog_channels_usedSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("number_of_scales"), number_of_scalesGet, number_of_scalesSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("padding"), paddingGet, paddingSet);
#if CV_MINOR_VERSION > 4 || (CV_MINOR_VERSION == 4 && CV_SUBMINOR_VERSION > 3)
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("psr_threshold"), psr_thresholdGet, psr_thresholdSet);
#endif
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("scale_lr"), scale_lrGet, scale_lrSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("scale_model_max_area"), scale_model_max_areaGet, scale_model_max_areaSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("scale_sigma_factor"), scale_sigma_factorGet, scale_sigma_factorSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("scale_step"), scale_stepGet, scale_stepSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("template_size"), template_sizeGet, template_sizeSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("use_channel_weights"), use_channel_weightsGet, use_channel_weightsSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("use_color_names"), use_color_namesGet, use_color_namesSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("use_gray"), use_grayGet, use_graySet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("use_hog"), use_hogGet, use_hogSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("use_rgb"), use_rgbGet, use_rgbSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("use_segmentation"), use_segmentationGet, use_segmentationSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("weights_lr"), weights_lrGet, weights_lrSet);
	Nan::SetAccessor(instanceTemplate, FF_NEW_STRING("window_function"), window_functionGet, window_functionSet);

	target->Set(FF_NEW_STRING("TrackerCSRTParams"), FF::getFunction(ctor));
};

NAN_METHOD(TrackerCSRTParams::New) {
	FF_ASSERT_CONSTRUCT_CALL(TrackerCSRTParams);
	FF_METHOD_CONTEXT("TrackerCSRTParams::New");
	TrackerCSRTParams* self = new TrackerCSRTParams();
	self->params = cv::TrackerCSRT::Params();
	self->Wrap(info.Holder());
	FF_RETURN(info.Holder());
};

#endif

#endif
