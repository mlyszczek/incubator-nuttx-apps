/****************************************************************************
 * apps/crypto/openssl_mbedtls_wrapper/mbedtls/md5.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <mbedtls/md5.h>
#include <openssl/md5.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

uint8_t *MD5(const uint8_t *data, size_t len,
             uint8_t out[MD5_DIGEST_LENGTH])
{
  if (mbedtls_md5(data, len, out) != 0)
    {
      return NULL;
    }

  return out;
}
