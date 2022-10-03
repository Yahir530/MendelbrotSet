#include "ComplexPlane.h"


ComplexPlane::ComplexPlane(float aspectRatio) {

    m_aspectratio = aspectRatio;
    m_view.setSize(BASE_WIDTH, -BASE_HEIGHT * m_aspectratio);
    m_view.setCenter(0.0, 0.0);
    m_zoomcount = 0;

}

void ComplexPlane::zoomIn() {

    m_zoomcount++;

    float x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomcount));
    float y = BASE_HEIGHT * m_aspectratio * (pow(BASE_ZOOM, m_zoomcount));

    m_view.setSize(x, y);

}

void ComplexPlane::zoomOut() {

    m_zoomcount--;

    float x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomcount));
    float y = BASE_HEIGHT * m_aspectratio * (pow(BASE_ZOOM, m_zoomcount));

    m_view.setSize(x, y);

}

void ComplexPlane::setCenter(Vector2f coordinate) 
{
    m_view.setCenter(coordinate);
}

View ComplexPlane::getView()
{
    return m_view;
}

void ComplexPlane::setMouseLocation(Vector2f coordinate) 
{
    m_mouselocation = coordinate;
}

void ComplexPlane::loadText(Text& text) {

    text.setCharacterSize(25);
    text.setFillColor(Color::Black);
    text.setPosition(0, 0);

    Vector2f centerCoordinate;
    centerCoordinate = m_view.getCenter();

    //Updates locations of mouse with coordinates x and y
    stringstream ss;
    ss << "MandelbrotSet" << endl;
    ss << "Center: (" << centerCoordinate.x << ", " << centerCoordinate.y << ")" << endl;
    ss << "Cursor: (" << m_mouselocation.x << ", " << m_mouselocation.y << ")" << endl;
    ss << "Left click = Zoom in" << endl;
    ss << "Right click = Zoom Out" << endl;
    text.setString(ss.str());

}

size_t ComplexPlane::countIterations(Vector2f coordinate) {

	complex<double> c(coordinate.x, coordinate.y);
	complex<double> z(0, 0);
	size_t iter = 0;

	while (abs(z) < 2 && iter < MAX_ITER)
	{
		z = z * z + c;
		iter++;
	}
	return iter;

}

//edit function parameters
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {

    if (count == MAX_ITER)
    {
        r = 0;
        g = 0;
        b = 0;
    }

    else if (count > 57) {
        r = 255;
        g = 255 * (0);
        b = 255 * (0);
    }

    else if (count > 49) {
        r = 255;
        g = 255 / 2;
        b = 255 * (0);
    }

    else if (count > 41)
    {
        r = 255 * (0.75);
        g = 255;
        b = 255 * (0);
    }

    else if (count > 33)
    {
        r = 255 * (0.5);
        g = 255;
        b = 255 * (0);
    }

    else if (count > 25)
    {
        r = 255 * (0);
        g = 255;
        b = 255 * (0.5);
    }

    else if (count > 17)
    {
        r = 255 * (0);
        g = 255 * (0.25);
        b = 255;
    }

    else if (count > 9)
    {
        r = 255 * (0.33);
        g = 255 * (0);
        b = 255;
    }

    else
    {
        r = 255;
        g = 255 * (0);
        b = 255;
    }


}
