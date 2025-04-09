import { Dimensions, SafeAreaView, Text, StyleSheet, TouchableOpacity, View} from "react-native";
import { useSharedValue } from "react-native-reanimated";
import Carousel, {
    ICarouselInstance,
} from "react-native-reanimated-carousel";
import React from "react";
import Setting from "@/app/interface/setting-interface";
import SettingBlock from "@/app/components/settingBlock";

let data: Setting[] = [
    {
        name: "Still One",
        colors: ["#ff0000"],
        flashingPattern: "STILL ONE",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Still Many",
        colors: ["#ff0000", "#ff4400", "#ff6a00", "#ff9100", "#ffee00", "#00ff1e", "#00ff44", "#00ff95", "#00ffff", "#0088ff", "#0000ff", "#8800ff", "#ff00ff", "#ff00bb", "#ff0088", "#ff0044"],
        flashingPattern: "STILL MANY",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Trace One",
        colors: ["#ff0000", "#3a9126", "#1d199b", "#504991", "#1e4b78", "#1e2d9b", "#538b99", "#1e1b37", "#1e4b0a", "#1d1b9b", "#1e2437", "#1e059b", "#1e4b37", "#1e1b19", "#1e4b9b", "#1e3214"],
        flashingPattern: "TRACE ONE",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Trace Many",
        colors: ["#A10000", "#CD3400", "#AC132A", "#131534", "#470023", "#D72300", "#CD260F", "#BE2852", "#BE1452", "#CD2623", "#D72100", "#470041", "#13374B", "#AC130A", "#CD3400", "#A1000C"],
        flashingPattern: "TRACE MANY",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Progressive",
        colors: ["#FF0000", "#FF5501", "#FF2800", "#FF0F02", "#0000EF", "#FF2D03", "#FF3B00", "#FF0200", "#FF0000", "#FF5501", "#FF2800", "#FF0F02", "#0000EF", "#FF2D03", "#FF3B00", "#FF0200"],
        flashingPattern: "PROGRESSIVE",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Strobe Change",
        colors: ["#A10000", "#CD3400", "#AC132A", "#131534", "#470023", "#D72300", "#CD260F", "#BE2852", "#BE1452", "#CD2623", "#D72100", "#470041", "#13374B", "#AC130A", "#CD3400", "#A1000C"],
        flashingPattern: "STROBE CHANGE",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Comfort Song",
        colors: ["#ff0000", "#ff4400", "#ff6a00", "#ff9100", "#ffee00", "#00ff1e", "#00ff44", "#00ff95", "#00ffff", "#0088ff", "#0000ff", "#8800ff", "#ff00ff", "#ff00bb", "#ff0088", "#ff0044"],
        flashingPattern: "COMFORT SONG",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Blender",
        colors: ["#FF00FF", "#000000", "#FF00FF", "#0000FF", "#FF00FF", "#FF0000", "#0000FF", "#0000FF", "#0000FF", "#FF00FF", "#FF0000", "#0000FF", "#0000FF", "#FF00FF", "#000000", "#FF0000"],
        flashingPattern: "BLENDER",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Techno",
        colors: ["#ff0000", "#ff4400", "#ff6a00", "#ff9100", "#ffee00", "#00ff1e", "#00ff44", "#00ff95", "#00ffff", "#0088ff", "#0000ff", "#8800ff", "#ff00ff", "#ff00bb", "#ff0088", "#ff0044"],
        flashingPattern: "TECHNO",
        direction: "inward",
        speed: 2,
    },
    {
        name: "Trance",
        colors: ["#00FF00", "#00C800", "#006400", "#009600", "#003200", "#00FF00", "#00B400", "#00E600", "#005A00", "#003200", "#00B400", "#00D200", "#000000", "#007800", "#006400", "#00FF00"],
        flashingPattern: "TRANCE",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Mold",
        colors: ["#A10000", "#CD3400", "#AC132A", "#131534", "#470023", "#D72300", "#CD260F", "#BE2852", "#BE1452", "#CD2623", "#D72100", "#470041", "#13374B", "#AC130A", "#CD3400", "#A1000C"],
        flashingPattern: "MOLD",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Funky",
        colors: ["#ff0000", "#3a9126", "#1d199b", "#504991", "#1e4b78", "#1e2d9b", "#538b99", "#1e1b37", "#1e4b0a", "#1d1b9b", "#1e2437", "#1e059b", "#1e4b37", "#1e1b19", "#1e4b9b", "#1e3214"],
        flashingPattern: "FUNKY",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Christmas",
        colors: ["#ff0000", "#ff4400", "#ff6a00", "#ff9100", "#ffee00", "#00ff1e", "#00ff44", "#00ff95", "#00ffff", "#0088ff", "#0000ff", "#8800ff", "#ff00ff", "#ff00bb", "#ff0088", "#ff0044"],
        flashingPattern: "CHRISTMAS",
        direction: "outward",
        speed: 3,
    },
];
let primKey: number[] = Array.from({ length: data.length }, (_, i) => i);
const width = Dimensions.get("window").width;
const height = Dimensions.get("window").height;

export default function Settings({navigation}: any) {
    const ref = React.useRef<ICarouselInstance>(null);
    const progress = useSharedValue<number>(0);
    const [currentIndex, setCurrentIndex] = React.useState(0);

    // TODO
    // Read from file
    // for each item in data, push the index to primKey

    return (
        <SafeAreaView style={styles.container}>
            {/*Back Button*/}
            <View style={styles.backButton}>
            <TouchableOpacity onPress={() => navigation.navigate("Welcome")}>
                <Text style={styles.backB}>    ⟨    </Text>
            </TouchableOpacity>
            </View>

            <View style={styles.notBackButton}>
                {/*Title*/}
                <View style={styles.title}>
                    <Text style={styles.text}>Settings</Text>
                </View>

                {/*See: https://reactnative.dev/docs/intro-react*/}
                {/*Carousel Focus Item*/}
                <SettingBlock style={styles.focusedItem} setting={data[currentIndex % data.length]} />

                {/*Carousel*/}
                <View style={styles.carCont}>
                    <Carousel
                        ref={ref}
                        data={primKey}
                        width={width}
                        defaultIndex={0}
                        enabled={true}
                        onProgressChange={(offset, absoluteProgress) => {
                            progress.value = offset;
                            setCurrentIndex(Math.round(absoluteProgress));
                            console.log('Current focused item:', data[currentIndex]);
                        }}
                        renderItem={({item}: {item: number}) => (
                            <SettingBlock style={styles.renderItem} setting={data[item]} />
                        )}
                        mode="parallax"
                        style={styles.carousel}
                    />

                </View>
            </View>
        </SafeAreaView>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
        backgroundColor: '#000000',
    },
    text: {
        fontFamily: "Thesignature",
        fontSize: 130,
        color: "#ffffff",
    },
    backButton: {
        height: height / 10,
        width: "100%",
    },
    notBackButton: {
        height: "90%",
    },
    renderItem: {
        borderStyle: "solid",
        borderWidth: 2,
        borderColor: "white",
        borderRadius: 7,
        width: width,
        height: height * 9 / 50,
        justifyContent: "center",
        alignItems: "center"
    },
    whiteText: {
        color: "white",
    },
    carCont: {
        flex: 1,
        justifyContent: "center",
        alignItems: "center"
    },
    carousel: {
        flex: 1,
        height: height * 2 /10,
        justifyContent: "center",
        alignItems: "flex-end"
    },
    focusedItem: {
        height: height / 2.5,
        borderStyle: "solid",
        borderWidth: 2,
        borderColor: "white",
        borderRadius: 7,
        justifyContent: "center",
        alignItems: "center"
    },
    title: {
        height: height * 2/10,
        justifyContent: "center",
        alignItems: "center"
    },
    backB: {
        color: '#ffffff',
        textAlign: 'left',
        fontSize: 30
    }
});