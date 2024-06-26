// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Canvas_imageInfo, 256, 256, true, 0) {
void draw(SkCanvas* canvas) {
    SkCanvas emptyCanvas;
    SkImageInfo canvasInfo = emptyCanvas.imageInfo();
    SkImageInfo emptyInfo;
    SkDebugf("emptyInfo %c= canvasInfo\n", emptyInfo == canvasInfo ? '=' : '!');
}
}  // END FIDDLE
