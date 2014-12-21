/*
 * FFmpegSurfaceView.java
 * Copyright (c) 2012 Jacek Marchwicki
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

package com.appunite.ffmpeg;

import android.annotation.TargetApi;
import android.content.Context;
import android.graphics.PixelFormat;
import android.os.Build;
import android.util.AttributeSet;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

@TargetApi(Build.VERSION_CODES.ICE_CREAM_SANDWICH)
public class FFmpegSurfaceView extends SurfaceView implements FFmpegDisplay, SurfaceHolder.Callback
{
	public static enum ScaleType
	{
		CENTER_CROP, CENTER_INSIDE, FIT_XY
	}

	private FFmpegPlayer ffmpegPlayer = null;
	private SurfaceHolder surfaceHolder = null;
	private boolean isCreated = false;

	public FFmpegSurfaceView(Context context)
	{
		this(context, null, 0);
	}

	public FFmpegSurfaceView(Context context, AttributeSet attrs)
	{
		this(context, attrs, 0);
	}

	public FFmpegSurfaceView(Context context, AttributeSet attrs, int defStyle)
	{
		super(context, attrs, defStyle);

		SurfaceHolder holder = getHolder();
		holder.setFormat(PixelFormat.RGBA_8888);
		holder.addCallback(this);
	}

	@Override
	public void setMpegPlayer(FFmpegPlayer fFmpegPlayer)
	{
		if (ffmpegPlayer != null)
		{
			throw new RuntimeException("setMpegPlayer could not be called twice");
		}

		ffmpegPlayer = fFmpegPlayer;
	}

	@Override
	public void surfaceChanged(SurfaceHolder holder, int format, int width, int height)
	{
	}

	@Override
	public void surfaceCreated(SurfaceHolder holder)
	{
		if (isCreated == true)
		{
			surfaceDestroyed(holder);
		}

		Surface surface = holder.getSurface();
		ffmpegPlayer.render(surface);
		surfaceHolder = holder;
		isCreated = true;
	}

	@Override
	public void surfaceDestroyed(SurfaceHolder holder)
	{
		stop();
	}

	public void stop()
	{
		ffmpegPlayer.stop();
		ffmpegPlayer.renderFrameStop();
		ffmpegPlayer.setMpegListener(null);
		ffmpegPlayer = null;

		Surface surface = surfaceHolder.getSurface();
		surface.release();
		surface = null;
		surfaceHolder.removeCallback(this);
		surfaceHolder = null;

		isCreated = false;
	}

	public long getCurrentPosition()
	{
		if (ffmpegPlayer == null)
		{
			return 0;
		}
		else
		{
			return ffmpegPlayer.mCurrentTimeUs;
		}
	}
}