#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    Display *display;
    Window window;
    Atom selection, target, clipboard;
    XEvent event;
    char *text;

    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, 1, 1, 0, 0, 0);
    selection = XInternAtom(display, "CLIPBOARD", False);
    target = XInternAtom(display, "UTF8_STRING", False);
    clipboard = XInternAtom(display, "XSEL_DATA", False);
    XConvertSelection(display, selection, target, clipboard, window, CurrentTime);
    XFlush(display);

    while (1) {
        XNextEvent(display, &event);
        if (event.type == SelectionNotify) {
            if (event.xselection.property == None) {
                printf("Failed to retrieve clipboard contents.\n");
                return 1;
            }
            Atom actual_type;
            int actual_format;
            unsigned long nitems, bytes_after;
            unsigned char *data = NULL;
            XGetWindowProperty(display, window, clipboard, 0, LONG_MAX, False,
                               AnyPropertyType, &actual_type, &actual_format,
                               &nitems, &bytes_after, &data);
            if (data != NULL) {
                text = (char *)data;
                printf("%s", text);
                XFree(data);
                break;
            }
        }
    }

    XCloseDisplay(display);
    return 0;
}
