// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(ColorGetA, 256, 256, false, 0) {
void draw(SkCanvas* canvas) {
    SkPaint paint;
    SkFont defaultFont = SkFont(fontMgr->matchFamilyStyle(nullptr, {}));
    paint.setColor(SK_ColorRED);
    for (int alpha = 255; alpha >= 0; alpha -= 17) {
        paint.setAlpha(alpha);
        canvas->drawRect({5, 5, 100, 20}, paint);
        SkAlpha alphaInPaint = SkColorGetA(paint.getColor());
        canvas->drawString(std::to_string(alphaInPaint).c_str(), 110, 18, defaultFont, paint);
        canvas->translate(0, 15);
    }
}
}  // END FIDDLE
