#pragma once

#include <map>
#include "GLTexture.h"

namespace Bengine {

	class TextureCache                                   // not static can have multiple instances
	{
	public:
		TextureCache();
		~TextureCache();

		GLTexture getTexture(std::string texturePath);

	private:
		std::map<std::string, GLTexture> _textureMap;
	};
}

