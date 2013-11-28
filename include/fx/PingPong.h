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

#include "fx/Effect.h"

AUD_NAMESPACE_BEGIN

/**
 * This factory plays another factory first normal, then reversed.
 * \note Readers from the underlying factory must be reversable with seeking.
 */
class PingPong : public Effect
{
private:
	// delete copy constructor and operator=
	PingPong(const PingPong&) = delete;
	PingPong& operator=(const PingPong&) = delete;

public:
	/**
	 * Creates a new ping pong factory.
	 * \param factory The input factory.
	 */
	PingPong(std::shared_ptr<ISound> factory);

	virtual std::shared_ptr<IReader> createReader();
};

AUD_NAMESPACE_END
