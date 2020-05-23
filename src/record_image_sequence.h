﻿/* Copyright (C) 2018 Yosshin(@yosshin4004) */

#ifndef _RECORD_IMAGE_SEQUENCE_H_
#define _RECORD_IMAGE_SEQUENCE_H_


#include "graphics.h"


struct RecordImageSequenceSettings {
	char directoryName[FILENAME_MAX];
	int xReso;
	int yReso;
	float startTime;
	float duration;
	float framesPerSecond;
	bool replaceAlphaByOne;
};

/* 連番画像の保存 */
bool RecordImageSequence(
	const RenderSettings *renderSettings,
	const RecordImageSequenceSettings *recordImageSequenceSettings
);


#endif
