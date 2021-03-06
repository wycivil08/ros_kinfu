/*
 * Copyright (c) 2013-2015, Riccardo Monica
 *   RIMLab, Department of Information Engineering, University of Parma, Italy
 *   http://www.rimlab.ce.unipr.it/
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions
 * and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other materials provided with
 * the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to
 * endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PARAMETERS_H
#define PARAMETERS_H

// input topics
#define PARAM_NAME_RESPONSE_TOPIC         "kinfu_response_topic"
#define PARAM_DEFAULT_RESPONSE_TOPIC      "/kinfu_response_topic"

#define PARAM_NAME_REQUEST_ACTION_NAME    "request_action_name"
#define PARAM_DEFAULT_REQUEST_ACTION_NAME "/kinfu_output/actions/request"

#define PARAM_NAME_REQUEST_ACTION_MAGIC   "kinfu_output_request_action_magic"
#define PARAM_DEFAULT_REQUEST_ACTION_MAGIC "KINFU_OUTPUT_ACTION_MAGIC_SOURCE_NAME"

#define PARAM_NAME_KINFU_REQUEST_TOPIC    "kinfu_request_topic"
#define PARAM_DEFAULT_KINFU_REQUEST_TOPIC "/kinfu_request_topic"

#endif // PARAMETERS_H
