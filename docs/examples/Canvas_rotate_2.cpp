// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Canvas_rotate_2, 256, 192, false, 0) {
void draw(SkCanvas* canvas) {
    SkPaint paint;
    SkFont font(fontMgr->matchFamilyStyle(nullptr, {}), 96);
    canvas->drawString("A1", 130, 100, font, paint);
    canvas->rotate(180, 130, 100);
    canvas->drawString("A1", 130, 100, font, paint);
}
}  // END FIDDLE
