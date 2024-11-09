module org.example.javafx1 {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires org.kordamp.bootstrapfx.core;

    opens org.example.javafx1 to javafx.fxml;
    exports org.example.javafx1;
}