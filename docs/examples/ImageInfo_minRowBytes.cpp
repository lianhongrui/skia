// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(ImageInfo_minRowBytes, 256, 256, true, 0) {
void draw(SkCanvas* canvas) {
    for (int shift = 24; shift < 31; ++shift) {
        int width = 1 << shift;
        SkImageInfo imageInfo =
                SkImageInfo::Make(width, 1, kRGBA_F16_SkColorType, kPremul_SkAlphaType);
        size_t minRowBytes = imageInfo.minRowBytes();
        bool widthTooLarge = !minRowBytes;
        SkDebugf("RGBA_F16 width %d (0x%08x) %s\n",
                 width, (unsigned int)width, widthTooLarge ? "too large" : "OK");
    }
}
}  // END FIDDLE
