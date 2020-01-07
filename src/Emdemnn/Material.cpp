#include "Material.h"
#include "Core.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Emdemnn
{
void Material::onLoad(const std::string& path, const std::string& shaderPath)
{
  shader = getCore()->getContext()->createShader();
  std::string fileShader;
  {
	// Create input file stream object and pass location of vert file.
	std::ifstream file(shaderPath);

	// Checking to see if file is open.
	if (!file.is_open())
	{
		throw std::exception();
	}
	else
	{
		// Checking if current line is not the end of the file.
		while (!file.eof())
		{
			// Create temp string *line*.
			std::string line;
			// Retrieves whole line from file and pushes into *line*.
			std::getline(file, line);
			// Add it to vertShader.
			fileShader += line + "\n";
		}
	}
	// Close the current open file.
	file.close();
  }
  shader->parse(fileShader);
  
  texture = getCore()->getContext()->createTexture();
  {
    int w = 0;
    int h = 0;
    int bpp = 0;

    unsigned char *data = stbi_load(path.c_str(),
      &w, &h, &bpp, 3);

    if(!data)
    {
      throw Exception("Failed to open image");
    }

    texture->setSize(w, h);

    for(int y = 0; y < h; y++)
    {
      for(int x = 0; x < w; x++)
      {
        int r = y * w * 3 + x * 3;

        texture->setPixel(x, y, vec3(
          data[r] / 255.0f,
          data[r + 1] / 255.0f,
          data[r + 2] / 255.0f));
      }
    }

    stbi_image_free(data);
  }
}
}