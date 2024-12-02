#include <gtk/gtk.h>
#include <stdio.h>

// Function declarations (placeholders)
void on_profile_edit_button_clicked(GtkButton *button, gpointer data);
void on_search_button_clicked(GtkButton *button, gpointer data);
void on_match_button_clicked(GtkButton *button, gpointer data);

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button_profile, *button_search, *button_match;
    GtkWidget *box;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "MatchUp");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Set up signal handlers for window close
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a box container to hold buttons
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Create and connect buttons with functions (placeholders)
    button_profile = gtk_button_new_with_label("Edit Profile");
    g_signal_connect(button_profile, "clicked", G_CALLBACK(on_profile_edit_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button_profile, FALSE, FALSE, 0);

    button_search = gtk_button_new_with_label("Search for Players");
    g_signal_connect(button_search, "clicked", G_CALLBACK(on_search_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button_search, FALSE, FALSE, 0);

    button_match = gtk_button_new_with_label("Find a Match");
    g_signal_connect(button_match, "clicked", G_CALLBACK(on_match_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button_match, FALSE, FALSE, 0);

    // Show all widgets in the window
    gtk_widget_show_all(window);

    // Run GTK main loop
    gtk_main();

    return 0;
}

// Function definitions (placeholders)
void on_profile_edit_button_clicked(GtkButton *button, gpointer data) {
    // Placeholder function for editing profile
    printf("Edit Profile button clicked\n");
}

void on_search_button_clicked(GtkButton *button, gpointer data) {
    // Placeholder function for searching players
    printf("Search button clicked\n");
}

void on_match_button_clicked(GtkButton *button, gpointer data) {
    // Placeholder function for matching players
    printf("Match button clicked\n");
}
