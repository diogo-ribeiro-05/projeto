
#include <iostream>
#include "SVGElements.hpp"
#include "external/tinyxml2/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

namespace svg
{
    void readSVG(const string& svg_file, Point& dimensions, vector<SVGElement *>& svg_elements)
    {
        XMLDocument doc;
        XMLError r = doc.LoadFile(svg_file.c_str());
        if (r != XML_SUCCESS)
        {
            throw runtime_error("Unable to load " + svg_file);
        }
        XMLElement *xml_elem = doc.RootElement();

        dimensions.x = xml_elem->IntAttribute("width");
        dimensions.y = xml_elem->IntAttribute("height");
        
        // TODO complete code -->
        
        for (XMLElement *child = xml_elem->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
        {
            if (child->Name() == (string)"ellipse"){
                Point center;
                center.x = child->IntAttribute("cx");
                center.y = child->IntAttribute("cy");

                Point radius;
                radius.x = child->IntAttribute("rx");
                radius.y = child->IntAttribute("ry");

                Color fill;
                fill = parse_color(child->Attribute("fill"));

                svg_elements.push_back(new Ellipse(fill, center, radius));
            }

            if (child->Name() == (string)"circle"){
                Point center;
                center.x = child->IntAttribute("cx");
                center.y = child->IntAttribute("cy");

                int radius;
                radius = child->IntAttribute("r");
            
                Color fill;
                fill = parse_color(child->Attribute("fill"));

                svg_elements.push_back(new Circle(fill, center, radius));
            }

            if (child->Name() == (string)"circle"){
                Point center;
                center.x = child->IntAttribute("cx");
                center.y = child->IntAttribute("cy");

                int radius;
                radius = child->IntAttribute("r");
            
                Color fill;
                fill = parse_color(child->Attribute("fill"));

                svg_elements.push_back(new Circle(fill, center, radius));
            }
        }
    }
}
oo
