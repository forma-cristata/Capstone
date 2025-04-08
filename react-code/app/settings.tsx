import { Dimensions, SafeAreaView, Text, StyleSheet, TouchableOpacity, View} from "react-native";
import { useSharedValue } from "react-native-reanimated";
import Carousel, {
    ICarouselInstance,
} from "react-native-reanimated-carousel";
import React from "react";
import Setting from "@/app/interface/setting-interface";
import settingBlock from "@/app/components/settingBlock";

let data: Setting[] = [
    {
        name: "Rainbow Road",
        colors: ["#ffffff", "#ff00ff", "#0000ff", "#000000", "#ffffff", "#ff00ff", "#0000ff", "#000000", "#ffffff", "#ff00ff", "#0000ff", "#000000", "#ffffff", "#ff00ff", "#0000ff", "#000000"],
        flashingPattern: "MOLD",
        direction: "outward",
        speed: 3,
    },
    {
        name: "Your mother",
        colors: ["#FF4D2E", "#2E8BFF", "#8A2EFF", "#FF2E8B", "#2EFF4D", "#4D2EFF", "#FF8A2E", "#2EFF8A", "#8B2EFF", "#FF2E4D", "#2E4DFF", "#4DFF2E", "#8AFF2E", "#2EFF4D", "#FF2E8A", "#4D8AFF"],
        flashingPattern: "TRACE ONE",
        direction: "inward",
        speed: 2,
    },
    {
        name: "Your father",
        colors: ["#7B3F6D", "#1AE5FF", "#FF4C2B", "#28D47C", "#9B42F5", "#E6B800", "#4287F5", "#FF6B9C", "#2BFF8E", "#8E44AD", "#FF5733", "#3498DB", "#27AE60", "#E74C3C", "#9B59B6", "#F1C40F"],
        flashingPattern: "TECHNO",
        direction: "outward",
        speed: 3,
    }
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

                {/*Setting block issues here*/ /*See: https://reactnative.dev/docs/intro-react*/}
                {/*Carousel Focus Item*/}
                <View style={styles.focusedItem}>
                    <Text style={styles.whiteText}>{data[currentIndex % data.length].name}</Text>
                    <Text style={styles.whiteText}>{data[currentIndex % data.length].colors.toString()}</Text>
                    <Text style={styles.whiteText}>{data[currentIndex % data.length].flashingPattern}</Text>
                    <Text style={styles.whiteText}>{data[currentIndex % data.length].direction}</Text>
                    <Text style={styles.whiteText}>{data[currentIndex % data.length].speed.toString()}</Text>
                </View>

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
                        renderItem={({item: item}:{ item: number }) => (
                            settingBlock({setting: data[item], style: styles.renderItem})
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