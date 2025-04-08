export default interface Setting {
    name: string;
    colors: string[];
    flashingPattern: string;
    direction: "outward" | "inward";
    speed: number;
}

