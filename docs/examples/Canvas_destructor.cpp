// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Canvas_destructor, 256, 256, false, 0) {
void draw(SkCanvas* canvas) {
    SkBitmap bitmap;
    bitmap.allocPixels(SkImageInfo::MakeN32Premul(200, 200));
    {
        SkCanvas offscreen(bitmap);
        SkPaint paint;
        SkFont font(fontMgr->matchFamilyStyle(nullptr, {}), 100);
        offscreen.drawString("ABC", 20, 160, font, paint);
        SkRect layerBounds = SkRect::MakeXYWH(32, 32, 192, 192);
        offscreen.saveLayerAlpha(&layerBounds, 128);
        offscreen.clear(SK_ColorWHITE);
        offscreen.drawString("DEF", 20, 160, font, paint);
    }
    canvas->drawImage(bitmap.asImage(), 0, 0);
}
}  // END FIDDLE
