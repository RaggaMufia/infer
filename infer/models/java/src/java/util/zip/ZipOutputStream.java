/*
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

package java.util.zip;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import com.facebook.infer.builtins.InferUndefined;


public class ZipOutputStream {

    public void putNextEntry(ZipEntry e) throws IOException {
        InferUndefined.can_throw_ioexception_void();
    }

    public void closeEntry() throws IOException {
        InferUndefined.can_throw_ioexception_void();
    }

}
