// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Bitmap_extractAlpha_2, 256, 160, false, 0) {
void draw(SkCanvas* canvas) {
    auto radiusToSigma = [](SkScalar radius) -> SkScalar {
         static const SkScalar kBLUR_SIGMA_SCALE = 0.57735f;
         return radius > 0 ? kBLUR_SIGMA_SCALE * radius + 0.5f : 0.0f;
    };
    SkBitmap alpha, bitmap;
    bitmap.allocN32Pixels(100, 100);
    SkCanvas offscreen(bitmap);
    offscreen.clear(0);
    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setColor(SK_ColorBLUE);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(20);
    offscreen.drawCircle(50, 50, 39, paint);
    paint.setMaskFilter(SkMaskFilter::MakeBlur(kNormal_SkBlurStyle, radiusToSigma(25)));
    SkIPoint offset;
    bitmap.extractAlpha(&alpha, &paint, &offset);
    paint.setColor(SK_ColorRED);
    canvas->drawImage(bitmap.asImage(), 0, -offset.fY, SkSamplingOptions(), &paint);
    canvas->drawImage(alpha.asImage(), 100 + offset.fX, 0, SkSamplingOptions(), &paint);
}
}  // END FIDDLE
