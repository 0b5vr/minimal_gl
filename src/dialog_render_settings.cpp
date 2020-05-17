﻿/* Copyright (C) 2018 Yosshin(@yosshin4004) */

#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "config.h"
#include "common.h"
#include "app.h"
#include "dialog_render_settings.h"
#include "resource/resource.h"


static void updateButtonState(HWND hDwnd){
	bool enableMultipleRenderTargets = GetDlgItemCheck(
		hDwnd, IDD_RENDER_SETTINGS_ENABLE_MULTIPLE_RENDER_TARGETS
	);
	EnableWindow(
		GetDlgItem(hDwnd, IDC_RENDER_SETTINGS_NUM_ENABLED_RENDER_TARGETS),
		enableMultipleRenderTargets
	);

	bool enableBackBuffer = GetDlgItemCheck(
		hDwnd, IDD_RENDER_SETTINGS_ENABLE_BACK_BUFFER
	);
	EnableWindow(
		GetDlgItem(hDwnd, IDD_RENDER_SETTINGS_ENABLE_MIPMAP_GENERATION),
		enableBackBuffer
	);
	EnableWindow(
		GetDlgItem(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_FILTER_NEAREST),
		enableBackBuffer
	);
	EnableWindow(
		GetDlgItem(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_FILTER_LINEAR),
		enableBackBuffer
	);
	EnableWindow(
		GetDlgItem(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_WRAP_REPEAT),
		enableBackBuffer
	);
	EnableWindow(
		GetDlgItem(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_WRAP_CLAMP_TO_EDGE),
		enableBackBuffer
	);
	EnableWindow(
		GetDlgItem(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_WRAP_MIRRORED_REPEAT),
		enableBackBuffer
	);
}

static LRESULT CALLBACK DialogFunc(
	HWND hDwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
){
	switch (uMsg) {
		/* ダイアログボックスの初期化 */
		case WM_INITDIALOG: {
			/* ピクセルフォーマットをラジオボタンに設定 */
			{
				int nIDDlgItem = 0;
				switch (AppRenderSettingsGetPixelFormat()) {
					case PixelFormatUnorm8RGBA: {
						nIDDlgItem = IDR_RENDER_SETTINGS_PIXEL_FORMAT_UNORM8_RGBA;
					} break;
					case PixelFormatFp16RGBA: {
						nIDDlgItem = IDR_RENDER_SETTINGS_PIXEL_FORMAT_FP16_RGBA;
					} break;
					case PixelFormatFp32RGBA: {
						nIDDlgItem = IDR_RENDER_SETTINGS_PIXEL_FORMAT_FP32_RGBA;
					} break;
					default : {
						assert(false);
					} break;
				}
				SetDlgItemCheck(hDwnd, nIDDlgItem, true);
			}

			/* マルチレンダーターゲット有効化フラグをチェックボックスに設定 */
			SetDlgItemCheck(
				hDwnd, IDD_RENDER_SETTINGS_ENABLE_MULTIPLE_RENDER_TARGETS,
				AppRenderSettingsGetEnableMultipleRenderTargetsFlag()
			);

			/* 有効レンダーターゲット数をコンボボックスに設定 */
			{
				HWND dlgItem = GetDlgItem(hDwnd, IDC_RENDER_SETTINGS_NUM_ENABLED_RENDER_TARGETS);

				/* コンボボックスに項目を送信 */
				for (int numRenderTargets = 1; numRenderTargets <= NUM_RENDER_TARGETS; numRenderTargets++) {
					char string[0x100];
					snprintf(string, sizeof(string), "MRT%d", numRenderTargets);
					SendMessage(
						dlgItem, CB_INSERTSTRING,
						numRenderTargets - 1 /* 0 でなく 1 から開始するので */,
						(LPARAM)string);
				}

				/* 初期状態で選択されている項目の指定 */
				SendMessage(
					dlgItem, CB_SETCURSEL,
					AppRenderSettingsGetNumEnabledRenderTargets() - 1,
					(LPARAM)0
				);
			}

			/* バックバッファ有効化フラグをチェックボックスに設定 */
			SetDlgItemCheck(
				hDwnd, IDD_RENDER_SETTINGS_ENABLE_BACK_BUFFER,
				AppRenderSettingsGetEnableBackBufferFlag()
			);

			/* ミップマップ生成有効化フラグをチェックボックスに設定 */
			SetDlgItemCheck(
				hDwnd, IDD_RENDER_SETTINGS_ENABLE_MIPMAP_GENERATION,
				AppRenderSettingsGetEnableMipmapGenerationFlag()
			);

			/* テクスチャフィルタをラジオボタンに設定 */
			{
				int nIDDlgItem = 0;
				switch (AppRenderSettingsGetTextureFilter()) {
					case TextureFilterNearest: {
						nIDDlgItem = IDR_RENDER_SETTINGS_TEXTURE_FILTER_NEAREST;
					} break;
					case TextureFilterLinear: {
						nIDDlgItem = IDR_RENDER_SETTINGS_TEXTURE_FILTER_LINEAR;
					} break;
					default : {
						assert(false);
					} break;
				}
				SetDlgItemCheck(hDwnd, nIDDlgItem, true);
			}

			/* テクスチャラップをラジオボタンに設定 */
			{
				int nIDDlgItem = 0;
				switch (AppRenderSettingsGetTextureWrap()) {
					case TextureWrapRepeat: {
						nIDDlgItem = IDR_RENDER_SETTINGS_TEXTURE_WRAP_REPEAT;
					} break;
					case TextureWrapClampToEdge: {
						nIDDlgItem = IDR_RENDER_SETTINGS_TEXTURE_WRAP_CLAMP_TO_EDGE;
					} break;
					case TextureWrapMirroredRepeat: {
						nIDDlgItem = IDR_RENDER_SETTINGS_TEXTURE_WRAP_MIRRORED_REPEAT;
					} break;
					default : {
						assert(false);
					} break;
				}
				SetDlgItemCheck(hDwnd, nIDDlgItem, true);
			}

			/* ボタン有効/無効ステート更新 */
			updateButtonState(hDwnd);

			/* メッセージは処理された */
			return 1;
		} break;

		/* UI 入力を検出 */
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
				/* OK */
				case IDOK: {
					/* ピクセルフォーマットをラジオボタンから取得 */
					PixelFormat pixelFormat = PixelFormatUnorm8RGBA;
					{
						if (GetDlgItemCheck(hDwnd, IDR_RENDER_SETTINGS_PIXEL_FORMAT_UNORM8_RGBA)) {
							pixelFormat = PixelFormatUnorm8RGBA;
						} else
						if (GetDlgItemCheck(hDwnd, IDR_RENDER_SETTINGS_PIXEL_FORMAT_FP16_RGBA)) {
							pixelFormat = PixelFormatFp16RGBA;
						} else
						if (GetDlgItemCheck(hDwnd, IDR_RENDER_SETTINGS_PIXEL_FORMAT_FP32_RGBA)) {
							pixelFormat = PixelFormatFp32RGBA;
						} else {
							AppErrorMessageBox(APP_NAME, "Invalid frame buffer.");
						}
					}

					/* マルチレンダーターゲット有効化フラグをチェックボックスから取得 */
					bool enableMultipleRenderTargets = GetDlgItemCheck(
						hDwnd, IDD_RENDER_SETTINGS_ENABLE_MULTIPLE_RENDER_TARGETS
					);

					/* 有効レンダーターゲット数をコンボボックスから取得 */
					int numRenderTargets = (int)SendMessage(
						GetDlgItem(hDwnd, IDC_RENDER_SETTINGS_NUM_ENABLED_RENDER_TARGETS),
						CB_GETCURSEL, 0, (LPARAM)0
					) + 1 /* 0 でなく 1 から開始するので */;

					/* バックバッファ有効化フラグをチェックボックスから取得 */
					bool enableBackBuffer = GetDlgItemCheck(
						hDwnd, IDD_RENDER_SETTINGS_ENABLE_BACK_BUFFER
					);

					/* ミップマップ生成フラグをチェックボックスから取得 */
					bool enableMipmapGeneration = GetDlgItemCheck(
						hDwnd, IDD_RENDER_SETTINGS_ENABLE_MIPMAP_GENERATION
					);

					/* テクスチャフィルタをラジオボタンから取得 */
					TextureFilter textureFilter = TextureFilterNearest;
					{
						if (GetDlgItemCheck(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_FILTER_NEAREST)) {
							textureFilter = TextureFilterNearest;
						} else
						if (GetDlgItemCheck(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_FILTER_LINEAR)) {
							textureFilter = TextureFilterLinear;
						} else {
							AppErrorMessageBox(APP_NAME, "Invalid texture filter.");
						}
					}

					/* テクスチャラップをラジオボタンから取得 */
					TextureWrap textureWrap = TextureWrapRepeat;
					{
						if (GetDlgItemCheck(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_WRAP_REPEAT)) {
							textureWrap = TextureWrapRepeat;
						} else
						if (GetDlgItemCheck(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_WRAP_CLAMP_TO_EDGE)) {
							textureWrap = TextureWrapClampToEdge;
						} else
						if (GetDlgItemCheck(hDwnd, IDR_RENDER_SETTINGS_TEXTURE_WRAP_MIRRORED_REPEAT)) {
							textureWrap = TextureWrapMirroredRepeat;
						} else {
							AppErrorMessageBox(APP_NAME, "Invalid texture wrap.");
						}
					}

					/* App に通知 */
					AppRenderSettingsSetPixelFormat(pixelFormat);
					AppRenderSettingsSetEnableMultipleRenderTargetsFlag(enableMultipleRenderTargets);
					AppRenderSettingsSetNumEnabledRenderTargets(numRenderTargets);
					AppRenderSettingsSetEnableBackBufferFlag(enableBackBuffer);
					AppRenderSettingsSetEnableMipmapGenerationFlag(enableMipmapGeneration);
					AppRenderSettingsSetTextureFilter(textureFilter);
					AppRenderSettingsSetTextureWrap(textureWrap);

					/* ダイアログボックス終了 */
					EndDialog(hDwnd, DialogRenderSettingsResult_Ok);

					/* メッセージは処理された */
					return 1;
				} break;

				/* キャンセル */
				case IDCANCEL: {
					/* ダイアログボックス終了 */
					EndDialog(hDwnd, DialogRenderSettingsResult_Canceled);

					/* メッセージは処理された */
					return 1;
				} break;

				/* Enable multiple render targets チェックボックスの更新  */
				case IDD_RENDER_SETTINGS_ENABLE_MULTIPLE_RENDER_TARGETS: {
					/* ボタン有効/無効ステート更新 */
					updateButtonState(hDwnd);
				} break;

				/* Enable back buffer チェックボックスの更新  */
				case IDD_RENDER_SETTINGS_ENABLE_BACK_BUFFER: {
					/* ボタン有効/無効ステート更新 */
					updateButtonState(hDwnd);
				} break;
			}
		} break;
	}

	/* メッセージは処理されなかった */
	return 0;
}


DialogRenderSettingsResult
DialogRenderSettings()
{
	return (DialogRenderSettingsResult)DialogBox(
		AppGetCurrentInstance(),
		"RENDER_SETTINGS",
		AppGetMainWindowHandle(),
		DialogFunc
	);
}

