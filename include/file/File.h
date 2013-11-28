/*******************************************************************************
 * Copyright 2009-2013 Jörg Müller
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

#include "ISound.h"
#include "util/Buffer.h"

#include <string>
#include <memory>

AUD_NAMESPACE_BEGIN

/**
 * This factory tries to read a sound file via all available file readers.
 */
class File : public ISound
{
private:
	/**
	 * The filename of the sound source file.
	 */
	std::string m_filename;

	/**
	 * The buffer to read from.
	 */
	std::shared_ptr<Buffer> m_buffer;

	// delete copy constructor and operator=
	File(const File&) = delete;
	File& operator=(const File&) = delete;

public:
	/**
	 * Creates a new factory.
	 * \param filename The sound file path.
	 */
	File(std::string filename);

	/**
	 * Creates a new factory.
	 * \param buffer The buffer to read from.
	 * \param size The size of the buffer.
	 */
	File(const data_t* buffer, int size);

	virtual std::shared_ptr<IReader> createReader();
};

AUD_NAMESPACE_END
