/*******************************************************************************
 * Copyright (c) 2015-2018 Skymind, Inc.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

//
// @author raver119@gmail.com
//

#include <helpers/logger.h>
#include <array/DataTypeUtils.h>
#include <types/float16.h>

namespace nd4j {
    DataType DataTypeUtils::fromInt(int val) {
        return (DataType) val;
    }

    DataType DataTypeUtils::fromFlatDataType(nd4j::graph::DataType dtype) {
        return (DataType) dtype;
    }

    int DataTypeUtils::asInt(DataType type) {
        return (int) type;
    }

    size_t DataTypeUtils::sizeOfElement(DataType type) {
        switch (type) {
            case DataType_UINT8:
            case DataType_INT8:
            case DataType_FLOAT8:
            case DataType_QINT8:
            case DataType_BOOL: return (size_t) 1;
            
            case DataType_HALF:
            case DataType_INT16:
            case DataType_QINT16:
            case DataType_UINT16: return (size_t) 2;

            case DataType_INT32:
            case DataType_UINT32:
            case DataType_HALF2:
            case DataType_FLOAT: return (size_t) 4;

            case DataType_UINT64:
            case DataType_INT64:
            case DataType_DOUBLE: return (size_t) 8;

            default: {
                nd4j_printf("Unknown DataType used: [%i]\n", asInt(type));
                throw std::runtime_error("Unknown DataType requested");
            }
        }
    }

    template <>
    DataType DataTypeUtils::fromT<float>() {
        return DataType_FLOAT;
    }

    template <>
    DataType DataTypeUtils::fromT<float16>() {
        return DataType_HALF;
    }

    template <>
    DataType DataTypeUtils::fromT<double>() {
        return DataType_DOUBLE;
    }

}