﻿/* Copyright (C) 2018 Yosshin(@yosshin4004) */

#define IDC_DUMMY												-1

#define IDI_DEFAULT												0x100
#define IDI_SMALL												0x101


#define IDM_OPEN_GRAPHICS_SHADER								0x200
#define IDM_OPEN_SOUND_SHADER									0x201
#define IDM_CAPTURE_SCREEN_SHOT									0x202
#define IDM_CAPTURE_CUBEMAP										0x203
#define IDM_CAPTURE_SOUND										0x204
#define IDM_EXPORT_EXECUTABLE									0x205
#define IDM_RECORD_IMAGE_SEQUENCE								0x206
#define IDM_QUIT												0x207

#define IDM_RENDER_SETTINGS										0x210
#define IDM_USER_TEXTURES										0x211
#define IDM_PREFERENCE_SETTINGS									0x212

#define IDM_CLEAR_ALL_TEXTURES_AND_FRAME_BUFFERS				0x220
#define IDM_RESET_CAMERA										0x221
#define IDM_EDIT_CAMERA_PARAMS									0x222
#define IDM_RESTART												0x223
#define IDM_PAUSE_AND_RESUME									0x224
#define IDM_SLOW_FORWARD										0x225
#define IDM_SLOW_BACKWARD										0x226
#define IDM_FAST_FORWARD										0x227
#define IDM_FAST_BACKWARD										0x228
#define IDM_TOGGLE_FULL_SCREEN									0x229

#define IDM_HELP_GRAPHICS_SHADER_UNIFORMS						0x230
#define IDM_HELP_SOUND_SHADER_UNIFORMS							0x231
#define IDM_HELP_PREPROCESSOR_DEFINITIONS						0x232
#define IDM_HELP_ABOUT											0x233


#define IDD_PREFERENCE_SETTINGS_AUTO_RESTART_BY_GRAPHICS_SHADER	0x300
#define IDD_PREFERENCE_SETTINGS_AUTO_RESTART_BY_SOUND_SHADER	0x301

#define IDR_RENDER_SETTINGS_PIXEL_FORMAT_UNORM8_RGBA			0x310
#define IDR_RENDER_SETTINGS_PIXEL_FORMAT_FP16_RGBA				0x311
#define IDR_RENDER_SETTINGS_PIXEL_FORMAT_FP32_RGBA				0x312
#define IDD_RENDER_SETTINGS_ENABLE_MULTIPLE_RENDER_TARGETS		0x313
#define IDC_RENDER_SETTINGS_NUM_ENABLED_RENDER_TARGETS			0x314
#define IDD_RENDER_SETTINGS_ENABLE_BACK_BUFFER					0x315
#define IDD_RENDER_SETTINGS_ENABLE_MIPMAP_GENERATION			0x316
#define IDR_RENDER_SETTINGS_TEXTURE_FILTER_NEAREST				0x317
#define IDR_RENDER_SETTINGS_TEXTURE_FILTER_LINEAR				0x318
#define IDR_RENDER_SETTINGS_TEXTURE_WRAP_REPEAT					0x319
#define IDR_RENDER_SETTINGS_TEXTURE_WRAP_CLAMP_TO_EDGE			0x31A
#define IDR_RENDER_SETTINGS_TEXTURE_WRAP_MIRRORED_REPEAT		0x31B
#define IDC_RENDER_SETTINGS_ENABLE_SWAP_INTERVAL_CONTROL		0x31C
#define IDR_RENDER_SETTINGS_SWAP_INTERVAL_ALLOW_TEARING			0x31D
#define IDR_RENDER_SETTINGS_SWAP_INTERVAL_HSYNC					0x31E
#define IDR_RENDER_SETTINGS_SWAP_INTERVAL_VSYNC					0x31F

#define IDD_EDIT_CAMERA_PARAMS_POS_X							0x320
#define IDD_EDIT_CAMERA_PARAMS_POS_Y							0x321
#define IDD_EDIT_CAMERA_PARAMS_POS_Z							0x322
#define IDD_EDIT_CAMERA_PARAMS_ANG_X							0x323
#define IDD_EDIT_CAMERA_PARAMS_ANG_Y							0x324
#define IDD_EDIT_CAMERA_PARAMS_ANG_Z							0x325
#define IDD_EDIT_CAMERA_PARAMS_FOV_Y							0x326

#define IDD_CAPTURE_SCREEN_SHOT_XRESO							0x330
#define IDD_CAPTURE_SCREEN_SHOT_YRESO							0x331
#define IDD_CAPTURE_SCREEN_SHOT_OUTPUT_FILE						0x332
#define IDD_CAPTURE_SCREEN_SHOT_BROWSE_OUTPUT_FILE				0x333
#define IDD_CAPTURE_SCREEN_SHOT_FORCE_REPLACE_ALPHA_BY_1		0x334

#define IDD_CAPTURE_CUBEMAP_RESO								0x340
#define IDD_CAPTURE_CUBEMAP_OUTPUT_FILE							0x341
#define IDD_CAPTURE_CUBEMAP_BROWSE_OUTPUT_FILE					0x342

#define IDD_CAPTURE_SOUND_OUTPUT_FILE							0x351
#define IDD_CAPTURE_SOUND_DURATION								0x352
#define IDD_CAPTURE_SOUND_AUTO_DETECT_DURATION					0x353
#define IDD_CAPTURE_SOUND_BROWSE_OUTPUT_FILE					0x354

#define IDD_EXPORT_EXECUTABLE_SCREEN_XRESO						0x360
#define IDD_EXPORT_EXECUTABLE_SCREEN_YRESO						0x361
#define IDD_EXPORT_EXECUTABLE_DURATION							0x362
#define IDD_EXPORT_EXECUTABLE_ENABLE_FRAME_COUNT_UNIFORM		0x363
#define IDD_EXPORT_EXECUTABLE_ENABLE_SOUND_DISPATCH_WAIT		0x364
#define IDD_EXPORT_EXECUTABLE_ALLOW_TEARING_FLIP				0x365
#define IDD_EXPORT_EXECUTABLE_OUTPUT_FILE						0x366
#define IDD_EXPORT_EXECUTABLE_BROWSE_OUTPUT_FILE				0x367
#define IDD_EXPORT_EXECUTABLE_SHADER_MINIFIER_NO_RENAMING		0x368
#define IDD_EXPORT_EXECUTABLE_SHADER_MINIFIER_NO_SEQUENCE		0x369
#define IDD_EXPORT_EXECUTABLE_SHADER_MINIFIER_SMOOTHSTEP		0x36A
#define IDD_EXPORT_EXECUTABLE_CRINKLER_COMPMODE_INSTANT			0x36B
#define IDD_EXPORT_EXECUTABLE_CRINKLER_COMPMODE_FAST			0x36C
#define IDD_EXPORT_EXECUTABLE_CRINKLER_COMPMODE_SLOW			0x36D
#define IDD_EXPORT_EXECUTABLE_CRINKLER_COMPMODE_VERYSLOW		0x36E
#define IDD_EXPORT_EXECUTABLE_CRINKLER_USE_TINYHEADER			0x36F
#define IDD_EXPORT_EXECUTABLE_CRINKLER_USE_TINYIMPORT			0x370

#define IDD_RECORD_IMAGE_SEQUENCE_SCREEN_XRESO					0x380
#define IDD_RECORD_IMAGE_SEQUENCE_SCREEN_YRESO					0x381
#define IDD_RECORD_IMAGE_SEQUENCE_START_TIME					0x382
#define IDD_RECORD_IMAGE_SEQUENCE_DURATION						0x383
#define IDD_RECORD_IMAGE_SEQUENCE_FRAMES_PER_SECOND				0x384
#define IDD_RECORD_IMAGE_SEQUENCE_OUTPUT_DIRECTORY				0x385
#define IDD_RECORD_IMAGE_SEQUENCE_BROWSE_OUTPUT_DIRECTORY		0x386
#define IDD_RECORD_IMAGE_SEQUENCE_FORCE_REPLACE_ALPHA_BY_1		0x387

#define IDD_CONFIRM_OVER_WRITE_FILE_NAME						0x390
#define IDD_CONFIRM_OVER_WRITE_DONT_ASK_AGAIN					0x391
#define IDD_CONFIRM_OVER_WRITE_YES								0x392

#define IDC_PROGRESS_BAR										0x3A0
#define IDC_PROGRESS_BAR_CURRENT_STATUS							0x3A1

#define IDD_GRAPHICS_SHADER_UNIFORMS_AVAILABLE_ON_EXE			0x3B0
#define IDD_GRAPHICS_SHADER_UNIFORMS_NOT_AVAILABLE_ON_EXE		0x3B1

#define IDD_SOUND_SHADER_UNIFORMS_AVAILABLE_ON_EXE				0x3C0
#define IDD_SOUND_SHADER_UNIFORMS_NOT_AVAILABLE_ON_EXE			0x3C1

#define IDD_PREPROCESSOR_DEFINITIONS							0x3D0

#define IDD_USER_TEXTURES_FILE_0								0x3E0
#define IDD_USER_TEXTURES_FILE_1								0x3E1
#define IDD_USER_TEXTURES_FILE_2								0x3E2
#define IDD_USER_TEXTURES_FILE_3								0x3E3
#define IDD_USER_TEXTURES_BROWSE_FILE_0							0x3E4
#define IDD_USER_TEXTURES_BROWSE_FILE_1							0x3E5
#define IDD_USER_TEXTURES_BROWSE_FILE_2							0x3E6
#define IDD_USER_TEXTURES_BROWSE_FILE_3							0x3E7

